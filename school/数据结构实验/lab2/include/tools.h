#ifndef TOOLS_H
#define TOOLS_H

#include "exception.h"
#include "any.h"
#include <stddef.h>

// 常用函数
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

// 防止 double free 的free函数
status nfree(any *_ptr);
// 任意变量交换函数
void swap(size_t itemSize,any a,any b);
// 数据转换
#define KB(x) ((x)*1024)
#define MB(x) (KB(x)*1024)
#define GB(x) (MB(x)*1024)
// utf8 读取
size_t read_utf8(utf8* res,byte buffer,size_t pos,size_t max);

#endif // TOOLS_H