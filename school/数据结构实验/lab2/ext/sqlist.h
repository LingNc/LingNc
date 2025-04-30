#ifndef SQLIST_H
#define SQLIST_H

#include <stddef.h>

typedef void *any;

struct inFunc{

};

typedef struct inFunc *infunc;

struct SqList{
    any _data;
    size_t _size;
    size_t _capacity;
    size_t _itemSize;
    infunc _func;
}; // 顺序表

#endif //SQLIST_H