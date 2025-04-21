#include "linklist.h"
#include "multiterm.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 按照规定格式打印多项式，形式如：x^4 - 3x^2 + 5
void print_multiterm(MutiTerm term, const char *name) {
    printf("%s：", name);
    bool first_term = true;
    bool is_zero = true; // 检查多项式是否为零

    if(term.type == LINKLIST) {
        node p = linklist_bgein(term._linklist);
        while(p) {
            int coe = p->data.coe;
            int exp = p->data.exp;

            if(coe != 0) {
                is_zero = false;

                // 处理系数符号
                if(first_term) {
                    first_term = false;
                    if(coe < 0) {
                        printf("-");
                        coe = -coe;
                    }
                } else {
                    if(coe < 0) {
                        printf(" - ");
                        coe = -coe;
                    } else {
                        printf(" + ");
                    }
                }

                // 根据指数打印项
                if(exp == 0) {
                    printf("%d", coe);
                } else if(exp == 1) {
                    if(coe == 1) {
                        printf("x");
                    } else {
                        printf("%dx", coe);
                    }
                } else {
                    if(coe == 1) {
                        printf("x^%d", exp);
                    } else {
                        printf("%dx^%d", coe, exp);
                    }
                }
            }

            p = p->next;
        }
    } else {
        for(size_t i = 0; i < sqlist_length(term._sqlist); i++) {
            ElemType e = sqlist_get(term._sqlist, i);
            int coe = e.coe;
            int exp = e.exp;

            if(coe != 0) {
                is_zero = false;

                // 处理系数符号
                if(first_term) {
                    first_term = false;
                    if(coe < 0) {
                        printf("-");
                        coe = -coe;
                    }
                } else {
                    if(coe < 0) {
                        printf(" - ");
                        coe = -coe;
                    } else {
                        printf(" + ");
                    }
                }

                // 根据指数打印项
                if(exp == 0) {
                    printf("%d", coe);
                } else if(exp == 1) {
                    if(coe == 1) {
                        printf("x");
                    } else {
                        printf("%dx", coe);
                    }
                } else {
                    if(coe == 1) {
                        printf("x^%d", exp);
                    } else {
                        printf("%dx^%d", coe, exp);
                    }
                }
            }
        }
    }

    // 如果多项式为空或所有系数为0，输出0
    if(is_zero || first_term) {
        printf("0");
    }

    printf("\n");
}

// 创建多项式函数
MutiTerm create_multiterm() {
    int n;
    printf("输入多项式的项数：");
    scanf("%d", &n);

    sqlist s = new_sqlist();
    int max_exp = -1;
    int term_count = 0;

    printf("输入多项式的各项（系数 指数）：\n");
    for(int i = 0; i < n; i++) {
        int coe, exp;
        scanf("%d %d", &coe, &exp);
        // 只保存系数不为0的项
        if(coe != 0) {
            sqlist_push_back(s, New_Elemtype(coe, exp));
            if(exp > max_exp) max_exp = exp;
            term_count++;
        }
    }

    // 根据稀疏性决定使用哪种数据结构
    MutiTerm term = new_multi(is_sparse(term_count, max_exp) ? LINKLIST : SQLIST);
    term.max_exp = max_exp;
    term.term_count = term_count;

    // 将数据从临时顺序表转移到多项式中
    if(term.type == LINKLIST) {
        for(int i = 0; i < term_count; i++) {
            ElemType e = sqlist_get(s, i);
            linklist_push_back(term._linklist, e);
        }
        printf("使用链表存储（稀疏多项式）\n");
    } else {
        for(int i = 0; i < term_count; i++) {
            ElemType e = sqlist_get(s, i);
            sqlist_push_back(term._sqlist, e);
        }
        printf("使用顺序表存储（密集多项式）\n");
    }

    // 释放临时顺序表
    sqlist_free(s);

    return term;
}

int main() {
    printf("============= 多项式运算程序 =============\n\n");

    // 创建第一个多项式
    printf("创建第一个多项式：\n");
    MutiTerm m1 = create_multiterm();

    // 创建第二个多项式
    printf("\n创建第二个多项式：\n");
    MutiTerm m2 = create_multiterm();

    // 多项式运算
    char op;
    MutiTerm result;

    // DEBUG
    printf("\nDEBUG: m1 = ");
    print_multiterm(m1, "m1");
    printf("DEBUG: m2 = ");
    print_multiterm(m2, "m2");

    printf("\n请输入运算指令（+ 相加，- 相减，* 相乘）：");
    scanf(" %c", &op);

    switch(op) {
        case '+': {
            printf("\n执行多项式加法...\n");
            result = multi_add(m1, m2);
            if(result.type == LINKLIST) {
                printf("结果多项式使用链表存储（稀疏多项式）\n");
            } else {
                printf("结果多项式使用顺序表存储（密集多项式）\n");
            }

            // 升幂输出
            printf("加法结果（升幂）：");
            multi_sort_by_exp_up(&result);
            print_multiterm(result, "加法结果（升幂）");

            // 降幂输出
            printf("加法结果（降幂）：");
            multi_sort_by_exp_down(&result);
            print_multiterm(result, "加法结果（降幂）");
            break;
        }
        case '-': {
            printf("\n执行多项式减法...\n");
            result = multi_sub(m1, m2);
            if(result.type == LINKLIST) {
                printf("结果多项式使用链表存储（稀疏多项式）\n");
            } else {
                printf("结果多项式使用顺序表存储（密集多项式）\n");
            }

            // 升幂输出
            printf("减法结果（升幂）：");
            multi_sort_by_exp_up(&result);
            print_multiterm(result, "减法结果（升幂）");

            // 降幂输出
            printf("减法结果（降幂）：");
            multi_sort_by_exp_down(&result);
            print_multiterm(result, "减法结果（降幂）");
            break;
        }
        case '*': {
            printf("\n执行多项式乘法...\n");
            result = multi_mul(m1, m2);
            if(result.type == LINKLIST) {
                printf("结果多项式使用链表存储（稀疏多项式）\n");
            } else {
                printf("结果多项式使用顺序表存储（密集多项式）\n");
            }

            // 升幂输出
            printf("乘法结果（升幂）：");
            multi_sort_by_exp_up(&result);
            print_multiterm(result, "乘法结果（升幂）");

            // 降幂输出
            printf("乘法结果（降幂）：");
            multi_sort_by_exp_down(&result);
            print_multiterm(result, "乘法结果（降幂）");
            break;
        }
        default: {
            printf("无效的运算指令\n");
            break;
        }
    }

    // 释放资源
    multi_free(&m1);
    multi_free(&m2);
    multi_free(&result);

    return 0;
}