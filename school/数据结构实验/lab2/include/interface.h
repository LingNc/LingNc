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
typedef any  (*init_func) (self,interfaces);
// 拷贝构造函数
typedef any  (*copy_func) (self,any);
// 清理函数
typedef any  (*clear_func)(self);
// 比较函数
typedef bool (*cmp_func)  (any,any);
// 释放函数
typedef any  (*free_func) (self);
// 打印函数
typedef void (*print_func)(self);

struct InterFaces{
    // 接口数量
    Byte count;
    // 柔性数组
    interface inters[];
}; // InterFaces

typedef struct InterFaces InterFaces;
typedef InterFaces *interfaces;

struct InterFace{
    // 元素大小
    size_t     _itemSize;
    // 接口的接口列表
    interfaces _subInters;
    // 函数接口
    init_func  init;
    copy_func  copy;
    clear_func clear;
    cmp_func   cmp;
    free_func  free;
    print_func print;
}; // InterFace


// 获取元素大小
#define    inters_size(self, index) ((self)->inters[index]->_itemSize)
// 获取默认元素大小
#define    inter_size(self) inters_size(self,0)
// 获取子接口
#define    inters_sub(self, index) ((self)->inters[index])
// 获取默认接口
#define    inter_sub(self) inters_sub(self,0)
// 初始化接口列表
// 先传入接口个数，后面传入 interface 接口
interfaces new_interfaces(Byte subnums,...);
any        interfaces_copy(interfaces self,interfaces other);
Exception  free_interfaces(interfaces self);

// 初始化接口
// 码表 i:init c:copy l:clear m:cmp f:free p:print
interface new_interface(size_t itemSize,interfaces subinters,string format,...);
// 释放接口
Exception free_interface(interface slef);

#endif //INTERFACE_H