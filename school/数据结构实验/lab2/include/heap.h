#ifndef HEAP_H
#define HEAP_H

#include "sqlist.h"
#include "interface.h"
#include <stddef.h>

struct Heap{
    sqlist _heap;
    // 堆大小
    size_t *_size;
    // 比较函数
    cmp_func cmp;
}; // Heap
typedef struct Heap Heap;
typedef Heap *heap;

heap new_heap(interface inter,cmp_func cmp);
heap new_heap_from(sqlist list,cmp_func cmp);
any heap_top(heap self);
size_t heap_size(heap self);
bool heap_empty(heap self);
Exception heap_pop(heap self);
Exception heap_push(heap self,any item);
Exception heap_clear(heap self);
Exception free_heap(heap self);

#endif // HEAP_H