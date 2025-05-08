#ifndef TOOLS_H
#define TOOLS_H

#include "exception.h"
#include "any.h"

// 常用函数
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

// 防止 double free 的free函数
status nfree(any *_ptr);
// 任意变量交换函数
void swap(size_t itemSize,any a,any b);

#endif // TOOLS_H