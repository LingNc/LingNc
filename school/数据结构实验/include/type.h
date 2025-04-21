#ifndef TYPE1_H
#define TYPE1_H
#include <stddef.h>
#include <stdlib.h>
#include <error.h>
// #include <stdbool.h>
// 元素类型
typedef struct {
    int coe, exp;
} ElemType;
typedef ElemType *elemtype;

elemtype new_elemtype() {
    elemtype e = (elemtype)malloc(sizeof(ElemType));
    if(e == NULL) {
        return NULL;
    }
    e->coe = 0;
    e->exp = 0;
    return e;
}

int elemtype_compare(elemtype a, elemtype b) {
    if(a->coe == b->exp && a->exp == b->exp) return 0;
    else return 1;
}

Status elemtype_free(elemtype e) {
    if(e == NULL) {
        return ERROR;
    }
    free(e);
    return OK;
}
#endif // TYPE1_H