#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "sqlist.h"
#include "pair.h"
#include <stdint.h>

// 节点
typedef struct Node Node;
typedef Node *node;
struct Node{
    node left,right;
    utf8 word;
};

// 哈夫曼树
struct Huffman{
    node _tree;
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

enum Table{
    Freque,
    Length,
    Code
};
typedef enum Table Table;
// typedef Table table;

// new
huffman new_huffman();
// Exception huffman_init(huffman self);
Exception huffman_load(huffman self,Table type,sqlist table);
sqlist huffman_encode(huffman self);
sqlist huffman_decode(huffman self);
Exception free_huffman(huffman self);

#endif // HUFFMAN_H