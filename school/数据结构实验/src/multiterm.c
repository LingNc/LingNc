#include "multiterm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 按指数升序排序
Status linklist_sort_by_exp(linklist self) {
    if(self == NULL || self->_length <= 1) {
        return OK; // 空链表或只有一个结点的链表已经有序
    }
    for(size_t i = 0; i < self->_length - 1; i++) {
        node curr = self->_root;
        for(size_t j = 0; j < self->_length - 1 - i; j++) {
            if(curr->data.exp > curr->next->data.exp) {
                ElemType temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
            }
            curr = curr->next;
        }
    }

    return OK;
}

// 按照指数升序排序
Status sqlist_sort_by_exp(sqlist self) {
    if(self == NULL || self->_length <= 1) {
        return OK;
    }
    for(size_t i = 0; i < self->_length - 1; i++) {
        for(size_t j = 0; j < self->_length - 1 - i; j++) {
            if(self->_data[j].exp > self->_data[j + 1].exp) {
                ElemType temp = self->_data[j];
                self->_data[j] = self->_data[j + 1];
                self->_data[j + 1] = temp;
            }
        }
    }

    return OK;
}

// 为多项式按指数升序排序的实现
Status multi_sort_by_exp_up(MutiTerm *term) {
    if(term == NULL) {
        return ERROR;
    }

    // 根据多项式的存储类型调用相应的排序函数
    if(term->type == LINKLIST) {
        return linklist_sort_by_exp(term->_linklist);
    } else if(term->type == SQLIST) {
        return sqlist_sort_by_exp(term->_sqlist);
    }

    return ERROR;
}

// 按降幂排序
Status multi_sort_by_exp_down(MutiTerm *term){
    if(term == NULL) {
        return ERROR;
    }

    // 先按升序排序
    multi_sort_by_exp_up(term);

    if(term->type == LINKLIST) {
        linklist new_list = new_linklist();
        if(new_list == NULL) return ERROR;

        // 获取原始链表长度
        size_t length = linklist_length(term->_linklist);
        if(length == 0) return OK; // 空列表无需排序

        // 从后往前插入，实现降序
        for(int i = length - 1; i >= 0; i--) {
            ElemType e = linklist_get(term->_linklist, i);
            linklist_push_back(new_list, e);
        }

        // 释放原链表并更新指针
        linklist old_list = term->_linklist;
        term->_linklist = new_list;
        linklist_free(old_list);
    } else if(term->type == SQLIST) {
        sqlist new_list = new_sqlist();
        if(new_list == NULL) return ERROR;

        // 获取原始顺序表长度
        size_t length = sqlist_length(term->_sqlist);
        if(length == 0) return OK; // 空列表无需排序

        // 从后往前插入，实现降序
        for(int i = length - 1; i >= 0; i--) {
            ElemType e = sqlist_get(term->_sqlist, i);
            sqlist_push_back(new_list, e);
        }

        // 释放原顺序表并更新指针
        sqlist old_list = term->_sqlist;
        term->_sqlist = new_list;
        sqlist_free(old_list);
    }

    return OK;
}
// 判断多项式是否为稀疏表示
bool is_sparse(int n, int max_exp) { return n < (max_exp + 1) * 0.3; }

// 创建一个新的多项式
MutiTerm new_multi(TypeOfTerm type) {
    MutiTerm term;
    term.type = type;

    if(type == LINKLIST)
        term._linklist = new_linklist();
    else
        term._sqlist = new_sqlist();
    return term;
}
// 获取表
void *multi_get(MutiTerm *term) {
    if(term == NULL) return NULL;
    if(term->type == LINKLIST) {
        return term->_linklist;
    } else {
        return term->_sqlist;
    }
}
// 多项式相加
MutiTerm multi_add(MutiTerm a, MutiTerm b) {
    // 按指数升序排序
    multi_sort_by_exp_up(&a);
    multi_sort_by_exp_up(&b);

    // 结果的最大指数
    int max_exp = (a.max_exp > b.max_exp) ? a.max_exp : b.max_exp;
    int term_count = 0;

    // 创建临时顺序表存储所有项
    sqlist temp = new_sqlist();

    // 根据多项式的存储类型进行不同的处理
    if(a.type == LINKLIST && b.type == LINKLIST) {
        node pa = linklist_bgein(a._linklist), pb = linklist_bgein(b._linklist);
        // 合并两个多项式的项
        while(pa && pb) {
            if(pa->data.exp == pb->data.exp) {
                // 同指数项，系数相加
                ElemType e = New_Elemtype(pa->data.coe + pb->data.coe, pa->data.exp);
                if(e.coe != 0) {
                    sqlist_push_back(temp, e);
                    term_count++;
                }
                node_next(&pa);
                node_next(&pb);
            } else if(pa->data.exp < pb->data.exp) {
                // pa指数小，先添加pa
                sqlist_push_back(temp, pa->data);
                term_count++;
                node_next(&pa);
            } else {
                // pb指数小，先添加pb
                sqlist_push_back(temp, pb->data);
                term_count++;
                node_next(&pb);
            }
        }
        // 处理剩余项
        while(pa) {
            sqlist_push_back(temp, pa->data);
            term_count++;
            node_next(&pa);
        }
        while(pb) {
            sqlist_push_back(temp, pb->data);
            term_count++;
            node_next(&pb);
        }
    } else if(a.type == SQLIST && b.type == SQLIST) {
        size_t i = 0, j = 0;
        while(i < sqlist_length(a._sqlist) && j < sqlist_length(b._sqlist)) {
            ElemType e1 = sqlist_get(a._sqlist, i);
            ElemType e2 = sqlist_get(b._sqlist, j);
            if(e1.exp == e2.exp) {
                // 同指数项，系数相加
                ElemType e = New_Elemtype(e1.coe + e2.coe, e1.exp);
                if(e.coe != 0) {
                    sqlist_push_back(temp, e);
                    term_count++;
                }
                i++;
                j++;
            } else if(e1.exp < e2.exp) {
                sqlist_push_back(temp, e1);
                term_count++;
                i++;
            } else {
                sqlist_push_back(temp, e2);
                term_count++;
                j++;
            }
        }
        // 处理剩余项
        while(i < sqlist_length(a._sqlist)) {
            sqlist_push_back(temp, sqlist_get(a._sqlist, i));
            term_count++;
            i++;
        }
        while(j < sqlist_length(b._sqlist)) {
            sqlist_push_back(temp, sqlist_get(b._sqlist, j));
            term_count++;
            j++;
        }
    } else if(a.type == LINKLIST && b.type == SQLIST) {
        node pa = linklist_bgein(a._linklist);
        size_t j = 0;
        while(pa && j < sqlist_length(b._sqlist)) {
            ElemType e1 = pa->data;
            ElemType e2 = sqlist_get(b._sqlist, j);
            if(e1.exp == e2.exp) {
                // 同指数项，系数相加
                ElemType e = New_Elemtype(e1.coe + e2.coe, e1.exp);
                if(e.coe != 0) {
                    sqlist_push_back(temp, e);
                    term_count++;
                }
                node_next(&pa);
                j++;
            } else if(e1.exp < e2.exp) {
                sqlist_push_back(temp, e1);
                term_count++;
                node_next(&pa);
            } else {
                sqlist_push_back(temp, e2);
                term_count++;
                j++;
            }
        }
        // 处理剩余项
        while(pa) {
            sqlist_push_back(temp, pa->data);
            term_count++;
            node_next(&pa);
        }
        while(j < sqlist_length(b._sqlist)) {
            sqlist_push_back(temp, sqlist_get(b._sqlist, j));
            term_count++;
            j++;
        }
    } else { // a.type == SQLIST && b.type == LINKLIST
        size_t i = 0;
        node pb = linklist_bgein(b._linklist);
        while(i < sqlist_length(a._sqlist) && pb) {
            ElemType e1 = sqlist_get(a._sqlist, i);
            ElemType e2 = pb->data;
            if(e1.exp == e2.exp) {
                // 同指数项，系数相加
                ElemType e = New_Elemtype(e1.coe + e2.coe, e1.exp);
                if(e.coe != 0) {
                    sqlist_push_back(temp, e);
                    term_count++;
                }
                i++;
                node_next(&pb);
            } else if(e1.exp < e2.exp) {
                sqlist_push_back(temp, e1);
                term_count++;
                i++;
            } else {
                sqlist_push_back(temp, e2);
                term_count++;
                node_next(&pb);
            }
        }
        // 处理剩余项
        while(i < sqlist_length(a._sqlist)) {
            sqlist_push_back(temp, sqlist_get(a._sqlist, i));
            term_count++;
            i++;
        }
        while(pb) {
            sqlist_push_back(temp, pb->data);
            term_count++;
            node_next(&pb);
        }
    }

    // 创建结果多项式
    MutiTerm result;
    result.type = (is_sparse(term_count, max_exp)) ? LINKLIST : SQLIST;
    result.max_exp = max_exp;
    result.term_count = term_count;

    if(result.type == LINKLIST) {
        result._linklist = new_linklist();
        for(size_t i = 0; i < sqlist_length(temp); i++) {
            ElemType e = sqlist_get(temp, i);
            linklist_push_back(result._linklist, e);
        }
    } else {
        result._sqlist = new_sqlist();
        for(size_t i = 0; i < sqlist_length(temp); i++) {
            ElemType e = sqlist_get(temp, i);
            sqlist_push_back(result._sqlist, e);
        }
    }

    // 释放临时顺序表
    sqlist_free(temp);

    return result;
}

// 多项式减法
MutiTerm multi_sub(MutiTerm a, MutiTerm b) {
    // 将b多项式的所有系数取负
    MutiTerm _b = b;
    void *temp=multi_get(&_b);
    if(_b.type == LINKLIST) {
        node p = linklist_bgein(temp);
        while(p){
            node_val(p)->coe=-(node_val(p)->coe);
            node_next(&p);
        }
    } else {
        for(size_t i = 0; i < sqlist_length(temp); i++) {
            ElemType e = sqlist_get(temp, i);
            e.coe = -e.coe;
            sqlist_set(temp, i, e);
        }
    }

    // 调用多项式加法
    return multi_add(a, _b);
}

// 多项式乘法
MutiTerm multi_mul(MutiTerm a, MutiTerm b) {
    // 按指数升序排序
    multi_sort_by_exp_up(&a);
    multi_sort_by_exp_up(&b);

    // 创建一个临时顺序表存储结果
    sqlist temp = new_sqlist();
    int max_exp = 0;  // 结果多项式的最大指数
    int term_count = 0;  // 结果多项式的项数

    // 根据多项式的存储类型进行不同的处理
    if (a.type == LINKLIST && b.type == LINKLIST) {
        // 链表 × 链表
        node pa = linklist_bgein(multi_get(&a));
        while (pa) {
            node pb = linklist_bgein(multi_get(&b));
            while (pb) {
                // 系数相乘，指数相加
                int new_coe = pa->data.coe * pb->data.coe;
                int new_exp = pa->data.exp + pb->data.exp;

                // 更新最大指数
                max_exp=max(max_exp,new_exp);

                // 将结果添加到临时顺序表
                ElemType e = New_Elemtype(new_coe, new_exp);
                sqlist_push_back(temp, e);
                term_count++;

                node_next(&pb);
            }
            node_next(&pa);
        }
    } else if (a.type == SQLIST && b.type == SQLIST) {
        // 顺序表 × 顺序表
        size_t a_length=sqlist_length(multi_get(&a));
        size_t b_length=sqlist_length(multi_get(&b));
        for(size_t i=0; i<a_length; i++){
            ElemType e1 = sqlist_get(a._sqlist, i);
            for (size_t j = 0; j < b_length; j++) {
                ElemType e2 = sqlist_get(b._sqlist, j);

                // 系数相乘，指数相加
                int new_coe = e1.coe * e2.coe;
                int new_exp = e1.exp + e2.exp;

                // 更新最大指数
                max_exp=max(max_exp,new_exp);

                // 将结果添加到临时顺序表
                ElemType e = New_Elemtype(new_coe, new_exp);
                sqlist_push_back(temp, e);
                term_count++;
            }
        }
    } else if (a.type == LINKLIST && b.type == SQLIST) {
        // 链表 × 顺序表
        node pa = linklist_bgein(multi_get(&a));
        while(pa){
            size_t b_length=sqlist_length(multi_get(&b));
            for(size_t j=0; j<b_length; j++){
                ElemType e2 = sqlist_get(multi_get(&b), j);

                // 系数相乘，指数相加
                int new_coe = pa->data.coe * e2.coe;
                int new_exp = pa->data.exp + e2.exp;

                // 更新最大指数
                max_exp=max(max_exp,new_exp);

                // 将结果添加到临时顺序表
                ElemType e = New_Elemtype(new_coe, new_exp);
                sqlist_push_back(temp, e);
                term_count++;
            }
            node_next(&pa);
        }
    } else {
        // 顺序表 × 链表
        size_t a_length=sqlist_length(multi_get(&a));
        for(size_t i=0; i<a_length; i++){
            ElemType e1 = sqlist_get(multi_get(&a), i);
            node pb = linklist_bgein(multi_get(&b));
            while (pb) {
                // 系数相乘，指数相加
                int new_coe = e1.coe * pb->data.coe;
                int new_exp = e1.exp + pb->data.exp;

                // 更新最大指数
                max_exp=max(max_exp,new_exp);

                // 将结果添加到临时顺序表
                ElemType e = New_Elemtype(new_coe, new_exp);
                sqlist_push_back(temp, e);
                term_count++;

                node_next(&pb);
            }
        }
    }

    // 创建另一个顺序表用于合并同类项
    sqlist merged = new_sqlist();
    int merged_count = 0;

    // 对临时顺序表按指数排序
    // for (size_t i = 0; i < temp->_length - 1; i++) {
    //     for (size_t j = 0; j < temp->_length - 1 - i; j++) {
    //         if (temp->_data[j].exp > temp->_data[j + 1].exp) {
    //             ElemType t = temp->_data[j];
    //             temp->_data[j] = temp->_data[j + 1];
    //             temp->_data[j + 1] = t;
    //         }
    //     }
    // }
    sqlist_sort_by_exp(temp);

    // 合并同类项
    if (sqlist_length(temp) > 0) {
        int current_exp = sqlist_get(temp, 0).exp;
        int current_coe = sqlist_get(temp, 0).coe;

        for (size_t i = 1; i < sqlist_length(temp); i++) {
            ElemType curr_elem = sqlist_get(temp, i);
            if (curr_elem.exp == current_exp) {
                current_coe += curr_elem.coe;
            } else {
                // 不是同类项，将前一个结果加入merged
                if (current_coe != 0) {
                    ElemType e = New_Elemtype(current_coe, current_exp);
                    sqlist_push_back(merged, e);
                    merged_count++;
                }
                current_exp = curr_elem.exp;
                current_coe = curr_elem.coe;
            }
        }

        if (current_coe != 0) {
            ElemType e = New_Elemtype(current_coe, current_exp);
            sqlist_push_back(merged, e);
            merged_count++;
        }
    }

    // 释放临时顺序表
    sqlist_free(temp);

    // 创建结果多项式
    MutiTerm result;
    // 根据稀疏性选择存储结构
    result.type = (is_sparse(merged_count, max_exp)) ? LINKLIST : SQLIST;
    result.max_exp = max_exp;
    result.term_count = merged_count;

    if (result.type == LINKLIST) {
        result._linklist = new_linklist();
        for (size_t i = 0; i < sqlist_length(merged); i++) {
            ElemType e = sqlist_get(merged, i);
            linklist_push_back(result._linklist, e);
        }
    } else {
        result._sqlist = new_sqlist();
        for (size_t i = 0; i < sqlist_length(merged); i++) {
            ElemType e = sqlist_get(merged, i);
            sqlist_push_back(result._sqlist, e);
        }
    }

    // 释放合并后的顺序表
    sqlist_free(merged);

    return result;
}

// 释放多项式资源
void multi_free(MutiTerm *term) {
    if(term == NULL) return;
    if(term->type == LINKLIST) {
        linklist_free(multi_get(term));
    } else {
        sqlist_free(multi_get(term));
    }
}

// 从表达式字符串解析多项式
MutiTerm parse_expression(const char* expr) {
    if (expr == NULL || *expr == '\0') {
        // 空表达式返回空多项式
        MutiTerm term = new_multi(SQLIST);
        term.max_exp = 0;
        term.term_count = 0;
        return term;
    }

    // 创建一个临时顺序表存储所有项
    sqlist temp = new_sqlist();
    int max_exp = 0;
    int term_count = 0;

    const char* p = expr;
    int sign = 1; // 1 为正，-1 为负

    while (*p) {
        int coe = 0;
        int exp = 0;
        bool has_x = false;

        // 跳过空格
        while (*p && isspace(*p)) p++;
        if (!*p) break;

        // 处理符号
        if (*p == '+') {
            sign = 1;
            p++;
        } else if (*p == '-') {
            sign = -1;
            p++;
        }

        // 跳过空格
        while (*p && isspace(*p)) p++;
        if (!*p) break;

        // 解析系数
        if (isdigit(*p)) {
            while (isdigit(*p)) {
                coe = coe * 10 + (*p - '0');
                p++;
            }
        } else if (*p == 'x' || *p == 'X') {
            // 如果直接是 x，系数为 1
            coe = 1;
        } else {
            // 非法输入，跳过此项
            while (*p && *p != '+' && *p != '-') p++;
            continue;
        }

        // 应用符号
        coe *= sign;

        // 跳过空格
        while (*p && isspace(*p)) p++;

        // 处理 x^n
        if (*p == 'x' || *p == 'X') {
            has_x = true;
            p++;

            // 跳过空格
            while (*p && isspace(*p)) p++;

            if (*p == '^') {
                p++;

                // 跳过空格
                while (*p && isspace(*p)) p++;

                // 解析指数
                if (isdigit(*p)) {
                    while (isdigit(*p)) {
                        exp = exp * 10 + (*p - '0');
                        p++;
                    }
                } else {
                    // 非法指数，默认为 1
                    exp = 1;
                }
            } else {
                // 无指数，默认为 1
                exp = 1;
            }
        }

        if (!has_x) {
            // 无变量项，指数为 0
            exp = 0;
        }

        // 更新最大指数
        if (exp > max_exp) {
            max_exp = exp;
        }

        // 添加到临时顺序表
        if (coe != 0) {  // 系数为 0 的项不添加
            sqlist_push_back(temp, New_Elemtype(coe, exp));
            term_count++;
        }

        // 跳过空格
        while (*p && isspace(*p)) p++;
    }

    // 创建多项式结果
    MutiTerm term = new_multi(is_sparse(term_count, max_exp) ? LINKLIST : SQLIST);
    term.max_exp = max_exp;
    term.term_count = term_count;

    // 转移数据到结果多项式
    if(term.type == LINKLIST) {
        for(size_t i = 0; i < sqlist_length(temp); i++) {
            ElemType e = sqlist_get(temp, i);
            linklist_push_back(term._linklist, e);
        }
    } else {
        for(size_t i = 0; i < sqlist_length(temp); i++) {
            ElemType e = sqlist_get(temp, i);
            sqlist_push_back(term._sqlist, e);
        }
    }

    // 释放临时顺序表
    sqlist_free(temp);

    // 对结果多项式排序
    multi_sort_by_exp_up(&term);

    return term;
}