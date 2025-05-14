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

// 新建堆 这个cmp 决定大顶堆小顶堆，满足条件就会进行调整 < 则小顶堆 > 大顶堆
heap new_heap(interfaces inter,cmp_func cmp);
// 从 sqlist 进行自动建堆，指定排序方式
heap new_heap_from(sqlist list,cmp_func cmp);
any heap_top(heap self);
size_t heap_size(heap self);
bool heap_empty(heap self);
Exception heap_pop(heap self);
Exception heap_push(heap self,any item);
Exception heap_clear(heap self);
Exception free_heap(heap self);
// 获取内部inter
#define heap_inter(self) sqlist_inter(self->_heap)

#endif // HEAP_H