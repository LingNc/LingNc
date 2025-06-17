#ifndef TOOLS_H
#define TOOLS_H

#include "exception.h"
#include "interface.h"
#include "any.h"
#include <stddef.h>
#include <stdbool.h>

// 常用函数
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

// 防止 double free 的free函数
status pfree(any *_ptr);
// 增加安全的函数
#define sfree(_ptr) pfree((any*)(_ptr))

// 移动函数
bool mmove(any _dest,any _src,interface _inter);
// 值移动
bool smove(any _dest,any _src,size_t _size);
// 移动转换函数
any  move(any _src,interface _inter);
// 指针交换函数
bool pswap(any *a,any *b);
// 值交换
bool sswap(any a,any b,size_t size);
// 移动交换
bool mswap(any a,any b,interface inter);
// 深拷贝交换
bool dswap(any a,any b,interface inter);

// 二分查找，找到有序数组中第一个满足条件的,没找到返回NULL
any bsearchf(any key,any base,size_t nmemb,size_t size,bool(*check)(any,any));

// 数据转换
#define KB(x) ((x)*1024)
#define MB(x) (KB(x)*1024)
#define GB(x) (MB(x)*1024)

// utf8 读取
int read_utf8(utf8* res, byte buffer, size_t pos, size_t max);

#endif // TOOLS_H