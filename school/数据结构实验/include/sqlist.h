#ifndef SQLIST_H
#define SQLIST_H

#include "error.h"
#include "type.h"

typedef struct {
    // 线性表
    ElemType *_data;
    // 元素大小
    size_t _elemsize;
    // 表的实际长度
    size_t _length;
    // 当前分配的存储容量
    size_t _capacity;
} SqList, *sqlist; // 顺序表的类型名

// 初始化函数
sqlist new_sqlist();
Status sqlist_init(sqlist self);
// 获取大小
size_t sqlist_size(sqlist self);
size_t sqlist_lenth(sqlist self);
// 获取元素
ElemType sqlist_get(sqlist self, size_t pos);
elemtype sqlist_at(sqlist self, size_t pos);
// 设置元素
Status sqlist_set(sqlist self, size_t index, ElemType val);
// 重设大小
Status sqlist_resize(sqlist self, size_t new_size);
// 插入元素
Status sqlist_insert(sqlist self, size_t pos, ElemType val);
// 删除元素
Status sqlist_delete(sqlist self, size_t pos);
// 尾部添加
Status sqlist_push_back(sqlist self, ElemType val);
// 尾部删除
Status sqlist_pop_back(sqlist self);
// 释放
void sqlist_free(sqlist self);
#endif // SQLIST_H