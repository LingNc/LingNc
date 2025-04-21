#ifndef MULTITERM_H
#define MULTITERM_H

#include <stdbool.h>
#include "error.h"
#include "linklist.h"
#include "sqlist.h"

#define max(a,b) ((a)>(b)?(a):(b))

typedef enum{
    LINKLIST,
    SQLIST
}TypeOfTerm;

typedef struct {
    TypeOfTerm type;
    int max_exp,term_count;
    union{
        linklist _linklist;
        sqlist _sqlist;
    };
}MutiTerm;

typedef MutiTerm *multiterm;

// 为多项式按指数升序排序
Status multi_sort_by_exp(MutiTerm *term);
// 判断多项式是否为稀疏
bool is_sparse(int term_count,int max_exp);
// 创建新的多项式
MutiTerm new_multi(TypeOfTerm type);
// 获取表
void *multi_get(MutiTerm *term);
// 多项式加法
MutiTerm multi_add(MutiTerm a, MutiTerm b);
// 多项式减法
MutiTerm multi_sub(MutiTerm a, MutiTerm b);
// 多项式乘法
MutiTerm multi_mul(MutiTerm a, MutiTerm b);
// 释放多项式资源
void multi_free(MutiTerm *term);
#endif // MULTITERM_H