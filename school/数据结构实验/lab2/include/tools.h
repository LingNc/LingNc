#ifndef TOOLS_H
#define TOOLS_H

#include "exception.h"
#include "any.h"

// 常用函数
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

// 防止 double free 的free函数
status nfree(any *_ptr);

#endif // TOOLS_H