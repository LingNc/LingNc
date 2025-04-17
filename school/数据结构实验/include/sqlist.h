#ifndef SQLIST_H
#define SQLIST_H

//元素类型

typedef int ElemType;
typedef struct{
    ElemType *elem;  //线性表
    int length;   //表的实际长度
    int listsize;   //当前分配的存储容量
}SqList;   //顺序表的类型名

#endif // SQLIST_H