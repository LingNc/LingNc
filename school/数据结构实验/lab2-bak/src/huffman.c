#include "huffman.h"
#include "tools.h"
#include "heap.h"
#include "huffcode.h"
#include "pair.h"
#include <stdlib.h>
#include <stdio.h>
// 树节点
huffnode new_huffnode(utf8 word){
    huffnode res = malloc(sizeof(HuffNode));
    if (res == NULL) return NULL;
    huffnode_init(res, NULL);
    res->word = word;
    return res;
}
huffnode huffnode_init(huffnode self, interfaces inter){
    (void)inter; // 消除未使用参数警告
    if (self == NULL) return NULL;
    self->left = NULL;
    self->right = NULL;
    self->word = 0;
    self->freq = 0;
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
static bool min_heap(any a,any b){
    return cast(huffnode,a)->freq < cast(huffnode,b)->freq;
}

// 从频率表构建树
static hufftree create_tree_from_freq(sqlist freq_t){
    printf("DEBUG: create_tree_from_freq - 开始\n");
    if (freq_t == NULL) return NULL;
    size_t size = sqlist_size(freq_t);
    if (size == 0) return NULL;
    printf("DEBUG: 频率表大小: %zu\n", size);

    // 根据频率表预构建储存节点的堆的列表 O(n)
    // 储存节点指针值 sqlist<huffnode*>
    printf("DEBUG: 准备创建interface\n");
    interface pnode_inter = new_interface(sizeof(huffnode*), NULL, "");
    printf("DEBUG: interface创建成功\n");
    interfaces pnode_inters = new_interfaces(NULL, 1, pnode_inter);
    printf("DEBUG: interfaces创建成功\n");
    printf("DEBUG: 准备创建sqlist，pnode_inters=%p\n", pnode_inters);
    if (pnode_inters) {
        printf("DEBUG: interfaces count=%d\n", pnode_inters->count);
        if (pnode_inters->count > 0 && pnode_inters->inters[0]) {
            printf("DEBUG: interface[0]->_itemSize=%zu\n", pnode_inters->inters[0]->_itemSize);
        }
    }
    sqlist node_list = new_sqlist(pnode_inters);
    printf("DEBUG: sqlist创建成功\n");
    printf("DEBUG: 开始填充node_list，总共%zu个字符\n", size);
    for (size_t i = 0; i < size; i++){
        printf("DEBUG: 处理第%zu个字符\n", i);
        // 取出频率表中的元素
        pair p = *(pair*)sqlist_at(freq_t, i);
        printf("DEBUG: 获取pair成功\n");
        // 创建节点
        utf8 ch = *(utf8*)p->first;
        printf("DEBUG: 获取字符: %lu\n", ch);
        huffnode node = new_huffnode(ch);
        printf("DEBUG: 创建huffnode成功\n");
        node->freq = *(size_t*)p->second;
        printf("DEBUG: 设置频率: %zu\n", node->freq);
        // 插入到列表中 注意值应该传值的指针
        sqlist_push_back(node_list, &node);
        printf("DEBUG: 插入到列表成功\n");
    }
    printf("DEBUG: 循环结束，准备创建堆\n");
    // 建堆 根据频率 小顶堆 O(logn) 但是之后每次索引表构建 是 O(nlogn) 目前不采用
    // heap h=new_heap_from(table,min_heap);
    // 建堆 根据频率 小顶堆 heap<huffnode*>
    printf("DEBUG: 调用new_heap_from\n");
    heap h = new_heap_from(node_list, (cmp_func)min_heap);
    printf("DEBUG: 堆创建成功\n");

    printf("DEBUG: 检查堆是否为空\n");
    if (h == NULL) {
        printf("DEBUG: 堆为空，返回NULL\n");
        return NULL;
    }
    printf("DEBUG: 堆不为空，继续处理\n");
    // 构建哈夫曼树
    printf("DEBUG: 开始构建哈夫曼树，堆大小: %zu\n", heap_size(h));
    while (heap_size(h) > 1){
        printf("DEBUG: 堆大小: %zu，继续合并节点\n", heap_size(h));
        // 取出两个最小的节点
        printf("DEBUG: 获取第一个节点\n");
        huffnode *left_ptr = (huffnode*)heap_top(h);
        huffnode left = *left_ptr;
        printf("DEBUG: 弹出第一个节点，频率: %zu\n", left->freq);
        heap_pop(h);
        printf("DEBUG: 获取第二个节点\n");
        huffnode *right_ptr = (huffnode*)heap_top(h);
        huffnode right = *right_ptr;
        printf("DEBUG: 弹出第二个节点，频率: %zu\n", right->freq);
        heap_pop(h);
        // 创建新的节点
        printf("DEBUG: 创建新的内部节点\n");
        huffnode node = new_huffnode(0);
        node->left = left;
        node->right = right;
        node->freq = left->freq + right->freq;
        printf("DEBUG: 新节点频率: %zu\n", node->freq);
        // 插入到堆中
        printf("DEBUG: 将新节点插入堆\n");
        heap_push(h, &node);
        printf("DEBUG: 插入成功\n");
    }
    // 获取构建的树根
    printf("DEBUG: 构建完成，准备获取根节点\n");
    printf("DEBUG: 最终堆大小: %zu\n", heap_size(h));
    huffnode *root_ptr = (huffnode*)heap_top(h);
    printf("DEBUG: 获取到堆顶指针\n");
    hufftree root = *root_ptr;
    printf("DEBUG: 获取到根节点，频率: %zu\n", root->freq);
    heap_pop(h);
    printf("DEBUG: 弹出根节点成功\n");
    // 释放堆
    free_heap(h);
    printf("DEBUG: 释放堆成功\n");
    // 释放节点列表
    free_sqlist(node_list);
    printf("DEBUG: 释放节点列表成功\n");
    return root;
}

// 静态临时全局变量
static sqlist g_sqlist_table;
static interfaces g_pair_inters;

// 递归创建字长表
static void create_length(hufftree node, size_t depth){
    if (node == NULL) return;
    // 叶子节点
    if (node->left == NULL && node->right == NULL){
        pair p = new_pair(&(node->word), &depth, g_pair_inters);
        sqlist_push_back(g_sqlist_table, &p);
    }
    create_length(node->left, depth + 1);
    create_length(node->right, depth + 1);
}

// 从树构造字长表
static sqlist create_length_from_tree(hufftree tree){
    printf("DEBUG: create_length_from_tree - 开始\n");
    if (tree == NULL) return NULL;
    printf("DEBUG: 创建pair_create_inters\n");
    sqlist table = new_sqlist(pair_create_inters());
    printf("DEBUG: 字长表sqlist创建成功\n");
    // 遍历树
    // 计算字长
    // pair<utf8,size_t> 单词 和 长度
    printf("DEBUG: 创建interfaces\n");
    interfaces inters=new_interfaces(
        NULL, 2,
        new_interface(sizeof(utf8),NULL,""),
        new_interface(sizeof(size_t), NULL, "")
    );
    printf("DEBUG: interfaces创建成功\n");
    // 初始化静态全局变量
    g_pair_inters=inters;
    g_sqlist_table = table;
    printf("DEBUG: 开始递归遍历树，根节点频率: %zu\n", tree->freq);
    // 递归函数创建
    create_length(tree,0);
    printf("DEBUG: 递归遍历完成\n");
    // hfm->_leng_t = table;
    // 保存 pairinter
    // hfm->_length_inter=inter;
    // 清空全局变量
    g_pair_inters=NULL;
    g_sqlist_table = NULL;
    return table;
}

// 子长表按照字长长度升序，utf8升序排序函数
// c_any : pair<utf8,size_t>
static bool length_asc_cmp(c_any a,c_any b){
    pair pa = *(pair*)a;
    pair pb = *(pair*)b;
    size_t len_a = *(size_t*)pa->second;
    size_t len_b = *(size_t*)pb->second;

    if(len_a == len_b){
        utf8 ch_a = *(utf8*)pa->first;
        utf8 ch_b = *(utf8*)pb->first;
        return ch_a < ch_b;
    }
    else{
        return len_a < len_b;
    }
}

// 比较函数包装器，用于sqlist_sort
static int length_cmp_wrapper(c_any a, c_any b) {
    return length_asc_cmp(a, b) ? -1 : (length_asc_cmp(b, a) ? 1 : 0);
}

// 从字长表构建范式哈夫曼编码表
static sqlist create_canonical_from_length(sqlist leng_t){
    if (leng_t == NULL) return NULL;
    // 升序排序字长表
    sqlist_sort(leng_t, length_cmp_wrapper);
    // 创建编码表接口
    interfaces pinter=new_interfaces(NULL, 2,
        // utf8 inter
        new_interface(sizeof(utf8),NULL,""),
        // huffcode inter
        huffcode_create_inters()
    );
    // 计算范式哈夫曼编码表
    size_t l_size=sqlist_size(leng_t);
    // 缓存 huffcode
    HuffCode cache;
    // 初始化 huffcode 为0
    huffcode_init(&cache);
    // 从第一个对 获取起始数据
    // pair<utf8,size_t>
    pair p = *(pair*)sqlist_at(leng_t,0);
    // 设置第一个编码的长度
    size_t first_len = *(size_t*)p->second;
    cache._size = (Byte)first_len;
    // 创建第一个编码条目
    // pair<utf8,huffcode>
    pair code_pair = new_pair(p->first, &cache, pinter);
    // 创建编码表
    // sqlist<pair<utf8,huffcode>>
    sqlist table = new_sqlist(pair_create_inters());
    sqlist_push_back(table, &code_pair);
    free_pair(code_pair);
    size_t last_len = *(size_t*)p->second;
    // 处理剩余的每个词
    for(size_t i = 1; i < l_size; i++){
        p = *(pair*)sqlist_at(leng_t, i);
        // 增加编码值
        huffcode_inc(&cache);
        size_t new_len = *(size_t*)p->second;
        // 如果长度增加，左移差值位
        // 左移编码 (newWordlen - len) 次
        if(new_len > last_len){
            huffcode_lshift(&cache, new_len - last_len);
            last_len = new_len;
        }
        // 设置编码长度（需要手动设置 _size 字段）
        cache._size = (Byte)new_len;
        // 为新的字符创建编码
        code_pair = new_pair(p->first, &cache, pinter);
        // 添加条目到编码表
        sqlist_push_back(table, &code_pair);
        free_pair(code_pair);
    }
    return table;
}

// 从范式哈夫曼编码构造范式哈夫曼树
hufftree create_tree_from_canonical(sqlist code_t){
    if (code_t == NULL) return NULL;
    // 创建树
    hufftree tree = new_huffnode(0);
    // 遍历编码表
    size_t size = sqlist_size(code_t);
    for (size_t i = 0; i < size; i++){
        // pair<utf8,huffcode>
        pair p = *(pair*)sqlist_at(code_t, i);
        // 取出字节
        utf8 word = *(utf8*)p->first;
        // 取出编码 - 这里需要正确处理huffcode
        // huffcode code = (huffcode)p->second;
        // 创建新节点插入到树中 - 暂时简单处理
        (void)word; // 消除未使用变量警告
        // TODO: 实现正确的树插入逻辑
        // hufftree_insert(tree, new_node);
    }
    return tree;
}

// 树操作
huffman new_huffman(){
    huffman self = malloc(sizeof(Huffman));
    self->_tree = NULL;
    self->_nodes = 0;
    self->_freq_t = NULL;
    self->_leng_t = NULL;
    self->_code_t = NULL;
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
        self->_freq_t = table;
        break;
    case Length:
        self->_leng_t = table;
        break;
    case Code:
        self->_code_t = table;
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
    // 根据不同的表是否存在来构建树
    // 表均不存在
    if(self->_freq_t==NULL&&
       self->_leng_t==NULL&&
       self->_code_t==NULL){
        return NULL;
    }
    // 频率表存在
    if(self->_freq_t!=NULL){
        // 从频率表构建树来统计字长
        printf("DEBUG: 准备从频率表构建树\n");
        hufftree tree_t=create_tree_from_freq(self->_freq_t);
        printf("DEBUG: create_tree_from_freq 返回成功\n");
        if(tree_t==NULL){
            // 异常报错
            printf("DEBUG: tree_t 为空，返回NULL\n");
            return NULL;
        }
        printf("DEBUG: tree_t 不为空，准备创建字长表\n");
        // 从临时树构建字长表
        sqlist l_table=create_length_from_tree(tree_t);
        printf("DEBUG: create_length_from_tree 返回成功\n");
        if(l_table==NULL){
            // 异常报错
            printf("DEBUG: l_table 为空，返回NULL\n");
            return NULL;
        }
        printf("DEBUG: l_table 不为空，继续处理\n");
        self->_leng_t = l_table;
        // 从字长表构建编码表
        self->_code_t = create_canonical_from_length(l_table);
        // 从编码表构建树
        self->_tree = create_tree_from_canonical(self->_code_t);
        // 释放临时树
        free_hufftree(tree_t);
        return self->_tree;
    }
    // 字长表存在，从字长表构建
    if(self->_leng_t!=NULL){
        self->_code_t = create_canonical_from_length(self->_leng_t);
        self->_tree = create_tree_from_canonical(self->_code_t);
        return self->_tree;
    }
    return NULL;
}

// 获得指定表
sqlist huffman_table(huffman self, Table type){
    if (self == NULL) return NULL;
    sqlist table = NULL;
    switch (type){
    case Freque:
        table = self->_freq_t;
        break;
    case Length:
        table = self->_leng_t;
        break;
    case Code:
        table = self->_code_t;
        break;
    default:
        break;
    }
    return table;
}

Exception free_huffman(huffman self) {
    if (self == NULL) return new_exception(ERROR, "free_huffman: 传入self指针为空!");

    // 释放树
    if (self->_tree != NULL) {
        free_hufftree(self->_tree);
    }

    // 释放表（注意：这些表可能是外部传入的，需要谨慎处理）
    if (self->_freq_t != NULL) {
        free_sqlist(self->_freq_t);
    }
    if (self->_leng_t != NULL) {
        free_sqlist(self->_leng_t);
    }
    if (self->_code_t != NULL) {
        free_sqlist(self->_code_t);
    }

    free(self);
    return new_exception(SUCCESS, "");
}