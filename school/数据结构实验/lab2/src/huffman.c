#include "huffman.h"
#include "tools.h"
#include "heap.h"
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


// 树操作
huffman new_huffman(){
    huffman self = malloc(sizeof(Huffman));
    self->_tree = NULL;
    self->_nodes = 0;
    self->_frequeTable = NULL;
    self->_lenthTalbe = NULL;
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
        self->_lenthTalbe = table;
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

// 建树
hufftree create_tree_from_freq(huffman hfm){
    if (hfm == NULL) return NULL;
    sqlist table = hfm->_frequeTable;
    if (table == NULL) return NULL;
    size_t size = sqlist_size(table);
    if (size == 0) return NULL;

    // 根据频率表预构建储存节点的堆的列表 O(n)
    // 储存节点指针值
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
    // 建堆 根据频率 小顶堆
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
    hfm->_tree = root;
    // 释放堆
    free_heap(h);
    // 释放节点列表
    free_sqlist(node_list);
}

// 静态临时全局变量
static sqlist g_sqlist_table;
static pairinter g_pair_inter;

// 递归创建字长表 
void create_length(hufftree node, size_t depth){
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
sqlist create_length_from_tree(huffman hfm){
    if (hfm == NULL) return NULL;
    hufftree tree = hfm->_tree;
    if (tree == NULL) return NULL;
    sqlist table = new_sqlist(pair_create_inter());
    // 遍历树
    // 计算字长
    // 由递归函数创建，初始化静态全局变量
    g_sqlist_table = table;
    // pair<utf8,size_t> 单词 和 长度
    interface utf8_inter= new_interface(sizeof(utf8), NULL, "");
    interface depth_inter = new_interface(sizeof(size_t), NULL, "");
    pairinter inter = new_pair_inter(utf8_inter, depth_inter);
    g_pair_inter = inter;
    create_length(tree, 0);
    hfm->_lenthTalbe = table;
    // 释放
    free_pair_inter(inter);
    // 清空全局变量
    g_pair_inter = NULL;
    g_sqlist_table = NULL;
    return table;
}

// 构造
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
        table = self->_lenthTalbe;
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