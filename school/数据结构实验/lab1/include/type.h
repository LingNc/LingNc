#ifndef TYPE1_H
#define TYPE1_H
#include <stddef.h>
#include <stdlib.h>
#include "error.h"
// #include <stdbool.h>
// 元素类型
typedef struct {
    int coe, exp;
} ElemType;
typedef ElemType *elemtype;

elemtype new_elemtype();

ElemType New_Elemtype(int coe,int exp);

int elemtype_compare(elemtype a,elemtype b);

Status elemtype_free(elemtype e);

#endif // TYPE1_H