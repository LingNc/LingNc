#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "sqlist.h"
#include "pair.h"
#include <stdint.h>

// 节点
typedef struct HuffNode HuffNode;
// 定义节点指针和树指针
typedef HuffNode *huffnode,*hufftree;
struct HuffNode{
    huffnode left,right;
    utf8 word;
    size_t freq;
};

huffnode new_huffnode(utf8 word);
huffnode huffnode_init(huffnode self,interface inter);
huffnode huffnode_clear(huffnode self);
// 递归删除
huffnode free_huffnode(huffnode self);
// 兼容函数
any free_hufftree(hufftree self);
// 哈夫曼树
struct Huffman{
    huffnode _tree;
    // 节点数量
    size_t _nodes;
    // 频率表
    // sqlist<pair<utf8,size_t>>
    sqlist _frequeTable;
    // 字长表
    // sqlist<pair<utf8,size_t>>
    sqlist _lenthTalbe;
    // 编码表
    // sqlist<pair<utf8,string>>
    sqlist _codeTable;
}; // Huffman
typedef struct Huffman Huffman;
typedef Huffman *huffman;

// 表类型
enum Table{
    Freque,  // 频率表
    Length,  // 字长表
    Code     // 编码表
};
typedef enum Table Table;
// typedef Table table;

// 树操作
huffman new_huffman();
// Exception huffman_init(huffman self);
// 导入指定类型表
Exception huffman_load(huffman self,Table type,sqlist table);
// 获得指定表
sqlist huffman_table(huffman self,Table type);
// 构造树
hufftree huffman_build(huffman self);
Exception free_huffman(huffman self);

#endif // HUFFMAN_H