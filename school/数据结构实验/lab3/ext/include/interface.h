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
typedef struct InterFaces InterFaces;
typedef InterFaces *interfaces;

struct InterFaces{
    // 接口数量
    Byte count;
    // 柔性数组
    interface inters[];
}; // InterFaces

// 初始化函数
typedef any  (*init_func) (self,interfaces);
// 拷贝构造函数
typedef any  (*copy_func) (self,c_any);
// 移动构造函数
typedef any  (*move_func) (self,any);
// 清理函数
typedef any  (*clear_func)(c_self);
// 比较函数
typedef bool (*cmp_func)  (c_any,c_any);
// 释放函数
typedef any  (*free_func) (self);
// 打印函数
typedef void (*print_func)(self);
struct InterFace{
    // 元素大小
    size_t     _itemSize;
    // 接口的接口列表
    interfaces _subInters;
    // 函数接口
    init_func  init;
    copy_func  copy;
    move_func  move;
    clear_func clear;
    cmp_func   cmp;
    free_func  free;
    print_func print;
}; // InterFace

// 获取接口
#define    inters_inter(self,index) ((self)->inters[index])
// 获取默认接口
#define    inters_dinter(self) inters_inter(self,0)
// 获取元素大小
#define    inters_size(self, index) inters_inter(self,index)->_itemSize
// 获取默认元素大小
#define    inters_dsize(self) inters_size(self,0)
// 获取子接口
#define    inters_sub(self, index) inters_inter(self,index)->_subInters
// 获取默认子接口
#define    inters_dsub(self) inters_sub(self,0)

// 初始化接口列表
// 先传入接口个数，后面传入 interface 接口
interfaces new_interfaces(any _g_reginter,Byte subnums,...);
// any        interfaces_copy(interfaces self,interfaces other);
Exception  free_interfaces(interfaces self);

// 获取元素大小
#define inter_size(self) (self->_itemSize)
// 获取子接口
#define inter_sub(self) (self->_subInters)

// 初始化接口
// 码表 i:init c:copy v:move l:clear m:cmp f:free p:print
interface new_interface(size_t itemSize,interfaces subinters,string format,...);
// interface new_interface(any _g_reginter,size_t itemSize,string format,...);
// 释放接口
Exception free_interface(interface self);

/* 接口设计风格
// 初始化接口
        //  1     2       3    4       5      6      7     8
// init-> pair< sqlist<sqlist<int>> , pair<sqlist<double>,int>> >
pair_1 = new_interfaces(NULL,2,
    new_interface(sizeof(SqList),
        "iclp",init_func,cmp_func,clear_func,copy_func
    ),
    new_interface(sizeof(SqList),
        "icpl",init_func,cmp_func,clear_func,copy_func),
)
sqlist_2 = new_interfaces(NULL,1
    new_interface(sizeof(SqList),
        "icpl",init_func,cmp_func,clear_func,copy_func
    )
)

sqlist_3 = new_interfaces(NULL,1,
    new_interface(sizeof(int),"")
)

// int_4 = NULL

pair_5 = new_interfaces(NULL,2
    new_interface(sizeof(int),"")
    new_interface(sizeof(SqList),
        "icpl",init_func,cmp_func,clear_func,copy_func
    )
)

sqlist_6 = new_interfaces(NULL,1,
    new_interface(sizeof(double),"")
)

// double_7 = NULL

// int_8 = NULL

// 初始化函数
// vector<vector<int>> a(n,vector<int>(m,(int)0))
//        pair< vector<vector<int>> , pair<vector<double>,int> >
        //  1     2       3    4       5      6      7     8
// init-> pair< sqlist<sqlist<int>> , pair<sqlist<double>,int> >
// pair_1<sqlist,sqlist>
new_initlist(2,
    arglist(pair_1,"%a%a",first,first),
    // sqlist_2<sqlist>
    new_initlist(1,
        arglist(sqlist_2,"%d",size),
        // sqlist_3<int>
        new_initlist(1,
            arglist(sqlist_3,"%d",int),
            // int_4
            NULL
        )
    ),
    // pair_5<sqlist,int>
    new_initlist(2,
        arglist(pair_5,"%d",int),
        // sqlist_6<double>
        new_initlist(1,
            arglist(sqlist_6,"%lf",double),
            // double_7
            NULL
        ),
        // int_8
        NULL
    )
)
*/

#endif //INTERFACE_H

