#ifndef SQLIST_H
#define SQLIST_H

#include "interface.h"
#include <stdbool.h>

// 设置初始化顺序表容量
#define SQLIST_INIT_SIZE 10
// 顺序表表指针 传入顺序表指针
#define sqlist_pointer(self) pointer(inters_dsize(self->_inter))
// inter 提取宏
#define sqlist_inter(self) inters_dinter(self->_inter)
#define sqlist_sinter(self) inters_dsub(self->_inter)
// 内部元素大小
#define sqlist_itemsize(self) (sqlist_inter(self)->_itemSize)

// 顺序表
struct SqList{
    // 数据
    any _data;
    // 当前的实际大小
    size_t _size;
    // 容量（当前的最大大小）
    size_t _capacity;
    interfaces _inter;
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

// 顺序表接口
Exception sqlist_init(sqlist self,interfaces inter);
// 深拷贝构造函数
any sqlist_copy(sqlist self,sqlist other);
any sqlist_move(sqlist dest,sqlist src);
Exception sqlist_clear(sqlist self);
void sqlist_print(sqlist self);
Exception free_sqlist(sqlist self);
interfaces sqlist_create_inter(interfaces subinters);

// 初始化顺序表
sqlist new_sqlist(interfaces inter);
Exception sqlist_resize(sqlist self,size_t newSize);
// sqlist sqlist_insert(sqlist self,size_t pos,any item);
size_t sqlist_size(sqlist self);
// inline size_t sqlist_itemsize(sqlist self);
any sqlist_at(sqlist self,int index);
// 移动构造修改
any sqlist_set(sqlist self,int index,any newItem);
// 深拷贝修改
any sqlist_set_c(sqlist self,int index,any newItem);
bool sqlist_empty(sqlist self);
// 移动构造传入
Exception sqlist_push_back(sqlist self,any item);
// 深拷贝传入
Exception sqlist_push_back_c(sqlist self,any item);
Exception sqlist_pop_back(sqlist self);
sqlist_iterator sqlist_begin(sqlist self);
sqlist_iterator sqlist_end(sqlist self);
// 返回c风格的指针 表示数组
any sqlist_c_data(sqlist self);
// 查找表 check 返回 1满足条件 0不满足,找到第一个满足条件的
any sqlist_bsearchf(sqlist self, any key, bool (*check)(any, any));
// 排序函数
any sqlist_sort(sqlist self, int (*cmp)(c_any,c_any));

// 初始化迭代器
sqlist_iterator new_sqlist_iterator(sqlist dest,int index);
sqlist_iterator sqlist_iterator_back(sqlist_iterator self);
sqlist_iterator sqlist_iterator_next(sqlist_iterator self);
any sqlist_iterator_visit(sqlist_iterator self);
Exception free_sqlist_iterator(sqlist_iterator self);

#endif //SQLIST_H