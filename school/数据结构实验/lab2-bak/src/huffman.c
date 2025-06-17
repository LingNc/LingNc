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
    if (freq_t == NULL) return NULL;
    size_t size = sqlist_size(freq_t);
    if (size == 0) return NULL;

    // 根据频率表预构建储存节点的堆的列表 O(n)
    interface pnode_inter = new_interface(sizeof(huffnode*), NULL, "");
    interfaces pnode_inters = new_interfaces(NULL, 1, pnode_inter);
    sqlist node_list = new_sqlist(pnode_inters);

    for (size_t i = 0; i < size; i++){
        // 取出频率表中的元素
        pair p = *(pair*)sqlist_at(freq_t, i);
        utf8 ch = *(utf8*)p->first;
        huffnode node = new_huffnode(ch);
        node->freq = *(size_t*)p->second;
        sqlist_push_back(node_list, &node);
    }

    // 建堆
    heap h = new_heap_from(node_list, (cmp_func)min_heap);
    if (h == NULL) {
        return NULL;
    }

    // 构建哈夫曼树
    while (heap_size(h) > 1){
        huffnode *left_ptr = (huffnode*)heap_top(h);
        huffnode left = *left_ptr;
        heap_pop(h);
        huffnode *right_ptr = (huffnode*)heap_top(h);
        huffnode right = *right_ptr;
        heap_pop(h);

        huffnode node = new_huffnode(0);
        node->left = left;
        node->right = right;
        node->freq = left->freq + right->freq;
        heap_push(h, &node);
    }

    // 获取构建的树根
    huffnode *root_ptr = (huffnode*)heap_top(h);
    hufftree root = *root_ptr;
    heap_pop(h);

    // 释放堆和节点列表
    free_heap(h);
    free_sqlist(node_list);
    return root;
}

// 静态临时全局变量
static sqlist g_sqlist_table;
static interfaces g_pair_inters;

// 递归创建字长表
static void create_length(hufftree node, size_t depth){
    if (node == NULL) {
        return;
    }

    // 检查递归深度，防止栈溢出
    // if (depth > 64) {
    //     printf("ERROR: 递归深度过深\n");
    //     return;
    // }

    // 叶子节点
    if (node->left == NULL && node->right == NULL){
        if (g_pair_inters == NULL) {
            printf("ERROR: g_pair_inters为空！\n");
            return;
        }
        pair p = new_pair(&(node->word), &depth, g_pair_inters);
        if (p != NULL) {
            Exception ex = sqlist_push_back(g_sqlist_table, &p);
            if (ex.status != SUCCESS) {
                printf("ERROR: sqlist_push_back失败: %s\n", ex.msg);
            }
        } else {
            printf("ERROR: new_pair失败！\n");
        }
        return;
    }

    // 先处理左子树
    if (node->left != NULL) {
        create_length(node->left, depth + 1);
    }

    // 再处理右子树
    if (node->right != NULL) {
        create_length(node->right, depth + 1);
    }
}

// 从树构造字长表
static sqlist create_length_from_tree(hufftree tree){
    if (tree == NULL) return NULL;

    // 创建字长表接口 - pair<utf8, size_t>
    interfaces length_pair_inters = new_interfaces(NULL, 2,
        new_interface(sizeof(utf8), NULL, ""),
        new_interface(sizeof(size_t), NULL, "")
    );

    // 为字长表创建pair指针接口 - 存储pair*
    interfaces pair_ptr_inters = pair_ptr_create_inters();

    // 创建字长表
    sqlist table = new_sqlist(pair_ptr_inters);
    if (table == NULL) {
        return NULL;
    }

    // 设置全局变量，供递归函数使用
    g_sqlist_table = table;
    g_pair_inters = length_pair_inters;

    // 递归遍历树构建字长表
    create_length(tree, 0);

    // 清空全局变量
    g_pair_inters = NULL;
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
sqlist create_canonical_from_length(sqlist leng_t){
    if (leng_t == NULL) return NULL;    printf("DEBUG: 开始创建范式霍夫曼编码表\n");

    // 计算范式哈夫曼编码表
    size_t l_size=sqlist_size(leng_t);

    // 如果字长表为空，返回空的编码表
    if (l_size == 0) {
        return new_sqlist(pair_create_inters());
    }

    // 升序排序字长表
    sqlist_sort(leng_t, length_cmp_wrapper);

    // 获取huffcode接口
    interfaces huffcode_inters = huffcode_create_inters();
    interface huffcode_inter = huffcode_inters->inters[0]; // 取出第一个接口

    // 创建编码表接口
    interfaces pinter = new_interfaces(NULL, 2,
        // utf8 inter
        new_interface(sizeof(utf8),NULL,""),
        // huffcode inter
        huffcode_inter
    );

    // 创建pair接口（用于sqlist存储）
    interfaces pair_inters = pair_create_inters();    // 缓存 huffcode - 使用简单的整数值而不是HuffCode结构
    uint64_t code_value = 0;

    // 从第一个对 获取起始数据
    pair p = *(pair*)sqlist_at(leng_t,0);
    size_t first_len = *(size_t*)p->second;
    printf("DEBUG: 第一个字符 %lu, 长度 %zu, 编码值 %lu\n",
           *(utf8*)p->first, first_len, code_value);

    // 创建第一个编码条目
    HuffCode first_code;
    huffcode_init(&first_code);
    first_code._code = code_value;
    first_code._size = (Byte)first_len;

    pair code_pair = new_pair(p->first, &first_code, pinter);
    sqlist table = new_sqlist(pair_inters);

    sqlist_push_back(table, &code_pair);
    free_pair(code_pair);

    size_t last_len = first_len;

    // 处理剩余的每个词
    for(size_t i = 1; i < l_size; i++){
        p = *(pair*)sqlist_at(leng_t, i);

        // 增加编码值
        code_value++;
        size_t new_len = *(size_t*)p->second;
        printf("DEBUG: 处理字符 %lu, 新长度 %zu, 旧长度 %zu, 增加后编码值 %lu\n",
               *(utf8*)p->first, new_len, last_len, code_value);

        // 如果长度增加，左移差值位
        if(new_len > last_len){
            code_value <<= (new_len - last_len);
            printf("DEBUG: 左移 %zu 位后编码值 %lu\n", new_len - last_len, code_value);
            last_len = new_len;
        }

        printf("DEBUG: 最终编码值 %lu, 长度 %zu\n", code_value, new_len);

        // 创建新的HuffCode
        HuffCode current_code;
        huffcode_init(&current_code);
        current_code._code = code_value;
        current_code._size = (Byte)new_len;

        // 为新的字符创建编码
        code_pair = new_pair(p->first, &current_code, pinter);
        sqlist_push_back(table, &code_pair);
        free_pair(code_pair);
    }
    return table;
}

// 辅助函数：向树中插入一个节点（基于编码）
static void hufftree_insert_by_code(hufftree tree, utf8 word, huffcode code) {
    if (tree == NULL || code == NULL) return;

    huffnode current = tree;

    // 如果编码长度为0，说明是根节点的字符
    if (code->_size == 0) {
        current->word = word;
        return;
    }

    // 从最高位开始遍历
    for (int i = code->_size - 1; i >= 0; i--) {
        // 检查第i位是否为1
        bool bit = (code->_code >> i) & 1;

        if (bit == 0) {
            // 向左走
            if (current->left == NULL) {
                current->left = new_huffnode(0);
            }
            current = current->left;
        } else {
            // 向右走
            if (current->right == NULL) {
                current->right = new_huffnode(0);
            }
            current = current->right;
        }
    }

    // 在叶子节点设置字符
    current->word = word;
}

// 从范式哈夫曼编码构造范式哈夫曼树
hufftree create_tree_from_canonical(sqlist code_t){
    if (code_t == NULL) return NULL;

    size_t size = sqlist_size(code_t);
    if (size == 0) return NULL;

    // 创建根节点
    hufftree tree = new_huffnode(0);

    // 遍历编码表
    for (size_t i = 0; i < size; i++){
        // pair<utf8,huffcode>
        pair p = *(pair*)sqlist_at(code_t, i);

        // 取出字符
        utf8 word = *(utf8*)p->first;

        // 取出编码 - p->second 指向 huffcode 结构体
        huffcode code = (huffcode)p->second;

        // 插入到树中
        hufftree_insert_by_code(tree, word, code);
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
        hufftree tree_t=create_tree_from_freq(self->_freq_t);
        if(tree_t==NULL){
            return NULL;
        }
        // 从临时树构建字长表
        sqlist l_table=create_length_from_tree(tree_t);
        if(l_table==NULL){
            return NULL;
        }
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

// 从编码表构建哈夫曼树（公开接口）
hufftree hufftree_from_code_table(sqlist code_table) {
    return create_tree_from_canonical(code_table);
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