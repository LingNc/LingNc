#include "type.h"

elemtype new_elemtype() {
    elemtype e = (elemtype)malloc(sizeof(ElemType));
    if(e == NULL) {
        return NULL;
    }
    e->coe = 0;
    e->exp = 0;
    return e;
}
ElemType New_Elemtype(int coe, int exp) {
    ElemType e;
    e.coe = coe;
    e.exp = exp;
    return e;
}
int elemtype_compare(elemtype a, elemtype b) {
    if(a->coe == b->exp && a->exp == b->exp)
        return 0;
    else
        return 1;
}

Status elemtype_free(elemtype e) {
    if(e == NULL) {
        return ERROR;
    }
    free(e);
    return OK;
}