#include "huffman.h"
#include "tools.h"
#include "heap.h"
#include "huffcode.h"
#include <stdlib.h>
// 树节点
huffnode new_huffnode(utf8 word){
    huffnode res = malloc(sizeof(HuffNode));
    if (res == NULL) return NULL;
    huffnode_init(res, NULL);
    return res;
}
huffnode huffnode_init(huffnode self, interface inter){
    if (self == NULL) return NULL;
    self->left = NULL;
    self->right = NULL;
    self->word = 0;
    return self;
}
huffnode huffnode_clear(huffnode self){
    if (self == NULL) return NULL;
    self->left = NULL;
    self->right = NULL;
    self->word = 0;
    return self;
}
huffnode free_huffnode(huffnode self){
    if (self == NULL) return NULL;
    free_huffnode(self->left);
    free_huffnode(self->right);
    huffnode_clear(self);
    sfree(self);
    return NULL;
}
// 释放树
any free_hufftree(hufftree self){
    return free_huffnode(self);
}



// 频率表的查找函数 找到第一个满足条件的
// static bool check_freq(any f,any dest){
//     // sqlist<pair<utf8,size_t>>
//     return *(size_t*)f >= *(size_t*)dest;
// }

// 小顶堆 频率
// any = huffnode*
static bool min_heap(any a, any b){
    return (*(huffnode*)a)->freq < (*(huffnode*)b)->freq;
}

// 从频率表构建树
static hufftree create_tree_from_freq(sqlist table){
    if (table == NULL) return NULL;
    size_t size = sqlist_size(table);
    if (size == 0) return NULL;

    // 根据频率表预构建储存节点的堆的列表 O(n)
    // 储存节点指针值 sqlist<huffnode*>
    interface pnode_inter = new_interface(sizeof(huffnode), NULL, "");
    sqlist node_list = new_sqlist(pnode_inter);
    for (int i = 0; i < size; i++){
        // 取出频率表中的元素
        pair p = sqlist_at(table, i);
        // 创建节点
        huffnode node = new_huffnode(*(utf8*)p->first);
        node->freq = *(size_t*)p->second;
        // 插入到列表中 注意值应该传值的指针
        sqlist_push_back(node_list, &node);
    }
    // 建堆 根据频率 小顶堆 O(logn) 但是之后每次索引表构建 是 O(nlogn) 目前不采用
    // heap h=new_heap_from(table,min_heap);
    // 建堆 根据频率 小顶堆 heap<huffnode*>
    heap h = new_heap_from(table, min_heap);
    // 构建哈夫曼树
    hufftree tree = NULL;
    while (heap_size(h) > 1){
        // 取出两个最小的节点
        huffnode left = *(huffnode*)heap_top(h);
        heap_pop(h);
        huffnode right = *(huffnode*)heap_top(h);
        heap_pop(h);
        // 创建新的节点
        huffnode node = new_huffnode(0);
        node->left = left;
        node->right = right;
        node->freq = left->freq + right->freq;
        // 插入到堆中
        heap_push(h, &node);
    }
    // 获取构建的树根
    hufftree root = *(huffnode*)heap_top(h);
    heap_pop(h);
    // 释放堆
    free_heap(h);
    // 释放节点列表
    free_sqlist(node_list);
    return root;
}

// 静态临时全局变量
static sqlist g_sqlist_table;
static pairinter g_pair_inter;

// 递归创建字长表
static void create_length(hufftree node, size_t depth){
    if (node == NULL) return;
    // 叶子节点
    if (node->left == NULL && node->right == NULL){
        pair p = new_pair(node->word, depth,g_pair_inter);
        sqlist_push_back(g_sqlist_table, &p);
    }
    create_length(node->left, depth + 1);
    create_length(node->right, depth + 1);
}

// 从树构造字长表
static sqlist create_length_from_tree(huffman hfm){
    if (hfm == NULL) return NULL;
    hufftree tree = hfm->_tree;
    if (tree == NULL) return NULL;
    sqlist table = new_sqlist(pair_create_inter());
    // 遍历树
    // 计算字长
    // 由递归函数创建，初始化静态全局变量
    g_sqlist_table = table;
    // pair<utf8,size_t> 单词 和 长度
    pairinter inter=new_pairinter(
        new_interface(sizeof(utf8), NULL, ""),
        new_interface(sizeof(size_t), NULL, "")
    );
    g_pair_inter=inter;
    create_length(tree, 0);
    hfm->_lengthTable = table;
    // 保存 pairinter
    // hfm->_length_inter=inter;
    // 清空全局变量
    g_pair_inter=NULL;
    g_sqlist_table = NULL;
    return table;
}

// 子长表按照字长长度升序，utf8升序排序函数
// c_any : pair<utf8,size_t>
static bool length_asc_cmp(c_any a,c_any b){
    if(visitp_cast(size_t,cast(pair,a)->second) == visitp_cast(size_t,cast(pair,b)->second)){
        return visitp_cast(utf8,cast(pair,a)->first) < visitp_cast(utf8,cast(pair,b)->first);
    }
    else{
        return visitp_cast(size_t,cast(pair,a)->second) < visitp_cast(size_t,cast(pair,b)->second);
    }
}

// 从字长表构建范式哈夫曼编码表
static sqlist create_canonical_from_length(sqlist length){
    if (length == NULL) return NULL;
    // 升序排序字长表
    sqlist_sort(length,length_asc_cmp);
    // 创建pairinter
    pairinter pinter=new_pairinter(
        // utf8 inter
        new_interface(sizeof(utf8),NULL,""),
        // huffcode inter
        huffcode_create_inter()
    );
    // 计算范式哈夫曼编码表
    size_t l_size=sqlist_size(length);
    // 缓存 huffcode
    HuffCode cache;
    // 初始化 huffcode 为0
    huffcode_init(&cache);
    // 从第一个对 获取起始数据
    // pair<utf8,size_t>
    pair p=sqlist_at(length,0);
    // 创建第一个编码条目
    // pair<utf8,huffcode>
    pair code_pair=new_pair(p->first,p->second,pinter);
    // 创建编码表
    // sqlist<pair<utf8,huffcode>>
    sqlist table=new_sqlist(pair_create_inter());
    sqlist_push_back(table,code_pair);
    free_pair(code_pair);
    size_t last_len=1;
    // 处理剩余的每个词
    for(size_t i=0;i<l_size;i++){
        p=sqlist_at(length,i);
        // 增加编码值
        huffcode_inc(&cache);
        size_t new_len=visitp_cast(size_t,p->second);
        // 如果长度增加，左移差值位
        // 左移编码 (newWordlen - len) 次
        if(new_len>last_len){
            huffcode_lshift(&cache,new_len-last_len);
            last_len=new_len;
        }
        // 为新的字符创建编码
        code_pair=new_pair(p->first,&cache,pinter);
        // 添加条目到编码表
        sqlist_push_back(table,code_pair);
        free_pair(code_pair);
    }
    return table;
}

// 树操作
huffman new_huffman(){
    huffman self = malloc(sizeof(Huffman));
    self->_tree = NULL;
    self->_nodes = 0;
    self->_frequeTable = NULL;
    self->_lengthTable = NULL;
    self->_codeTable = NULL;
    return self;
}
// Exception huffman_init(huffman self);
// 导入指定类型表
Exception huffman_load(huffman self, Table type, sqlist table){
    if (self == NULL) return new_exception(ERROR, "huffman_load: 传入self指针为空!");
    if (table == NULL) return new_exception(ERROR, "huffman_load: 传入table指针为空!");
    Exception e = new_exception(SUCCESS, "");
    switch (type){
    case Freque:
        self->_frequeTable = table;
        break;
    case Length:
        self->_lengthTable = table;
        break;
    case Code:
        self->_codeTable = table;
        break;
    default:
        e.status = ERROR;
        e.msg = "huffman_load: type错误!";
        break;
    }
    return e;
}

// 构建树
hufftree huffman_build(huffman self){

}

// 获得指定表
sqlist huffman_table(huffman self, Table type){
    if (self == NULL) return NULL;
    sqlist table = NULL;
    switch (type){
    case Freque:
        table = self->_frequeTable;
        break;
    case Length:
        table = self->_lengthTable;
        break;
    case Code:
        table = self->_codeTable;
        break;
    default:
        break;
    }
    return table;
}

Exception free_huffman(huffman self);