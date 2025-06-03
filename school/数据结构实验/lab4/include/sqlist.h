#ifndef SQLIST_H
#define SQLIST_H

#include <redtype.h>

// 顺序表
typedef struct{
    RedType  r[MAXSIZE+1];
    int      length; /*参加排序元素的实际个数*/
}SqList;
typedef struct SqList SqList;
typedef SqList *sqlist;

#endif //SQLIST_H