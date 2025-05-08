#ifndef INTERFACE_H
#define INTERFACE_H

#include "exception.h"
#include "any.h"
#include <stddef.h>
#include <stdbool.h>

// 是否启用接口错误捕获，如果启用该接口需要返回exception类型的值
#define CAP_INTER_ERROR

// 任意类型接口
// 函数类型预先定义
typedef struct InterFace InterFace;
typedef InterFace *interface;
// 初始化函数
typedef any (*init_func)(self,interface);
// 拷贝构造函数
typedef any (*copy_func)(self,any);
// 清理函数
typedef any(*clear_func)(self);
// 比较函数
typedef bool(*cmp_func)(any,any);
// 释放函数
typedef any(*free_func)(self);

struct InterFace{
    // 元素大小
    size_t _itemSize;
    // 接口的接口
    interface _subinter;
    // 函数接口
    init_func init;
    copy_func copy;
    clear_func clear;
    cmp_func cmp;
    free_func free;
}; // InterFace

// 定义结束符号
#define inter_end NULL
// 初始化接口
// 顺序 init,clear,cmp,free
interface new_interface(size_t itemSize,interface subinter,...);
// 释放接口
Exception free_interface(interface slef);
// 获取元素大小
size_t inter_item_size(interface self);

#endif //INTERFACE_H