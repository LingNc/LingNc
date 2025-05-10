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
    any _subinter;
    // 函数接口
    init_func init;
    copy_func copy;
    clear_func clear;
    cmp_func cmp;
    free_func free;
}; // InterFace

// 初始化接口
// 码表 i:init c:copy l:clear m:cmp f:free
interface new_interface(size_t itemSize,any subinter,string format,...);
// 获取元素大小
size_t inter_size(interface self);
// 获取子接口
interface inter_subinter(interface self);
// 释放接口
Exception free_interface(interface slef);
// 获取元素大小
size_t inter_item_size(interface self);

#endif //INTERFACE_H