#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "sqlist.h"
#include "pair.h"
#include <stdint.h>

// 节点
typedef struct HuffNode HuffNode;
typedef HuffNode *huffnode;
struct HuffNode{
    huffnode left,right;
    utf8 word;
    size_t freq;
};
// 树结构
typedef huffnode tree;

huffnode new_huffnode(utf8 word);
huffnode huffnode_init(huffnode self,interface inter);
huffnode huffnode_clear(huffnode self);
huffnode free_huffnode(huffnode self);

// 哈夫曼树
struct Huffman{
    huffnode _tree;
    // 节点数量
    size_t _nodes;
    // 表 sqlist<pair<utf8,size_t>>
    // 频率表
    sqlist _frequeTable;
    // 字长表
    sqlist _lenthTalbe;
    // 编码表
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
tree huffman_build(huffman self);
Exception free_huffman(huffman self);

#endif // HUFFMAN_H