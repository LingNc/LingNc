#ifndef SQLIST_H
#define SQLIST_H

#include "type1.h"
#include "error.h"

//元素类型
typedef int ElemType;
typedef ElemType *elemtype;
typedef struct{
    //线性表
    ElemType *_data;
    // 元素大小
    size_t _elemsize;
    //表的实际长度
    size_t _length;
    //当前分配的存储容量
    size_t _capacity;
}SqList,*sqlist;   //顺序表的类型名

// 初始化函数
sqlist new_sqlist();
Status sqlist_init(sqlist);
// 获取大小
size_t sqlist_size(sqlist);
size_t sqlist_lenth(sqlist);
// 获取元素
ElemType sqlist_get(sqlist,size_t);
elemtype sqlist_at(sqlist,size_t);
// 设置元素
Status sqlist_set(sqlist,size_t,ElemType);
// 重设大小
Status sqlist_resize(sqlist,size_t);
// 插入元素
Status sqlist_insert(sqlist,size_t,ElemType);
// 删除元素
Status sqlist_delete(sqlist,size_t);
// 尾部添加
Status sqlist_push_back(sqlist,ElemType);
// 尾部删除
Status sqlist_pop_back(sqlist);
// 释放
void sqlist_free(sqlist);
#endif // SQLIST_H