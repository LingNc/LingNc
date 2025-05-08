#ifndef SQLIST_H
#define SQLIST_H

#include "interface.h"
#include <stdbool.h>

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
typedef struct SqList_Iterator SqList_Iterator;
typedef SqList_Iterator *sqlist_iterator;
struct SqList_Iterator{
    // 顺序表
    sqlist _list;
    // 当前元素的位置
    size_t _index;
    // 当前元素的指针
    any _curItem;
    // 上一个迭代器
    sqlist_iterator (*back)(sqlist_iterator self);
    // 下一个迭代器
    sqlist_iterator (*next)(sqlist_iterator self);
}; // SqList_Iterator


// 初始化顺序表
sqlist new_sqlist(interface inter);
Exception sqlist_init(sqlist self,interface inter);
Exception sqlist_resize(sqlist self,size_t newSize);
// sqlist sqlist_insert(sqlist self,size_t pos,any item);
size_t sqlist_size(sqlist self);
size_t sqlist_get_itemsize(sqlist self);
any sqlist_at(sqlist self,int index);
bool sqlist_empty(sqlist self);
Exception sqlist_clear(sqlist self);
Exception sqlist_push_back(sqlist self,any item);
Exception sqlist_pop_back(sqlist self);
sqlist_iterator sqlist_begin(sqlist self);
sqlist_iterator sqlist_end(sqlist self);
// 返回c风格的指针 表示数组
any sqlist_c_data(sqlist self);
Exception free_sqlist(sqlist self);

// 初始化迭代器
sqlist_iterator new_sqlist_iterator(sqlist dest,int index);
sqlist_iterator sqlist_iterator_back(sqlist_iterator self);
sqlist_iterator sqlist_iterator_next(sqlist_iterator self);
any sqlist_iterator_visit(sqlist_iterator self);
Exception free_sqlist_iterator(sqlist_iterator self);

#endif //SQLIST_H