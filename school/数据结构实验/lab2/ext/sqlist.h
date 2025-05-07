#ifndef SQLIST_H
#define SQLIST_H

#include <stddef.h>

// 如果没有引入string库
#ifndef STRING_H
    typedef char *string;
#endif

// 泛型定义
typedef void *any,*self;

// 错误信号
enum Status{
    // 成功
    SUCCESS=1,
    // 警告
    WARRING,
    // 失败
    ERROR,
};
typedef enum Status Status;
typedef Status status;

// 状态退化函数，状态按照 success,warring,error 等级向下递减，从不会上升
status status_down(status *self,status new_status);

// 防止 double free 的free函数
status nfree(any _ptr);

// 异常捕获
struct Exception{
    // 错误类型
    status status;
    // 错误信息
    string msg;
};
typedef struct Exception Exception;
typedef Exception *exception;

// 新建异常
Exception new_exception(status status,string msg);
// 传递异常,累积异常
Exception exception_pass(exception self,string new_msg);
// 获取异常的状态
status exception_get(exception self);
// 异常降级
Exception exception_down(exception self,status new_status);
// 释放异常
status free_exception(exception self);

// 任意类型接口
// 函数类型预先定义
// 初始化函数
typedef any (*init_func)(self,interface);
// 释放函数
typedef any (*free_func)(self);

struct InterFace{
    // 元素大小
    size_t _itemSize;
    // 接口的接口
    struct InterFace *subinter;
    // 函数接口
    init_func init;
    free_func free;
}; // InterFace
typedef struct InterFace InterFace;
typedef InterFace *interface;

// 定义结束符号
#define inter_end NULL
// 初始化接口
interface new_interface(size_t itemSize,...);
// 释放接口
Exception free_interface(interface slef);

// 设置初始化顺序表容量
#define SQLIST_INIT_SIZE 10

// 顺序表
struct SqList{
    // 数据
    any _data;
    // 当前的实际大小
    size_t _size;
    // 容量（当前的最大大小）
    size_t _capacity;
    interface _inter;
}; // SqList

typedef struct SqList SqList;
typedef SqList *sqlist;

// 顺序表迭代器
struct SqList_Iterator{
    // 当前元素的位置
    size_t _cur;
    // 当前元素的指针
    any _curItem;
    // 顺序表
    sqlist _list;
    // 上一个迭代器
    sqlist_iterator (*last)(sqlist_iterator self);
    // 下一个迭代器
    sqlist_iterator (*next)(sqlist_iterator self);
}; // SqList_Iterator

typedef struct SqList_Iterator SqList_Iterator;
typedef SqList_Iterator *sqlist_iterator;

// 初始化顺序表
sqlist new_sqlist(interface inter);
sqlist sqlist_init(sqlist self,interface inter);
Exception sqlist_resize(sqlist self,size_t newSize);
// sqlist sqlist_insert(sqlist self,size_t pos,any item);
size_t sqlist_size(sqlist self);
any sqlist_at(sqlist self,int index);
Exception sqlist_push_back(sqlist self,any item);
Exception sqlist_pop_back(sqlist self);
Exception free_sqlist(sqlist self);
sqlist_iterator sqlist_begin(sqlist self);
sqlist_iterator sqlist_end(sqlist self);

// 初始化迭代器
sqlist_iterator new_sqlist_iterator(sqlist dest,int index);
sqlist_iterator sqlist_iterator_last(sqlist_iterator self);
sqlist_iterator sqlist_iterator_next(sqlist_iterator self);
sqlist_iterator free_sqlist_iterator(sqlist dest);

#endif //SQLIST_H