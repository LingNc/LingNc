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
status pfree(any* _ptr);
// 增加安全的函数
// status nfree(any *_ptr)
#define sfree(_ptr) pfree((any*)(_ptr))

// 指针交换函数
bool pswap(any* a, any* b);
// 浅拷贝交换
bool sswap(const any a,const any b,size_t size);
// 深拷贝交换
bool dswap(const any a,const any b,interface inter);

// 二分查找，找到有序数组中第一个满足条件的,没找到返回NULL
any bsearchf(any key,any base,size_t nmemb,size_t size,bool(*check)(any,any));

// 数据转换
#define KB(x) ((x)*1024)
#define MB(x) (KB(x)*1024)
#define GB(x) (MB(x)*1024)

// utf8 读取
int read_utf8(utf8* res, byte buffer, size_t pos, size_t max);

#endif // TOOLS_H