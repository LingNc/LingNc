#include "linklist.h"
#include "multiterm.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// 创建多项式函数 - 数字方式输入
MutiTerm create_multiterm_numeric() {
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

    // 对多项式按指数排序
    multi_sort_by_exp_up(&term);

    return term;
}

// 创建多项式函数 - 表达式方式输入
MutiTerm create_multiterm_expression() {
    char expr[256]; // 用于存储表达式的缓冲区

    printf("输入多项式表达式 (如：2x^3 + 3x^4 + x^2)：\n");

    // 清空输入缓冲区，确保不会卡住
    int c;
    // 仅在第一次输入时需要清除换行符
    static int first_call = 1;
    if (first_call) {
        while ((c = getchar()) != '\n' && c != EOF);
        first_call = 0;
    }

    if (fgets(expr, sizeof(expr), stdin) == NULL) {
        fprintf(stderr, "读取表达式失败\n");

        // 返回空多项式
        MutiTerm term = new_multi(SQLIST);
        term.max_exp = 0;
        term.term_count = 0;
        return term;
    }

    // 移除换行符
    size_t len = strlen(expr);
    if (len > 0 && expr[len-1] == '\n') {
        expr[len-1] = '\0';
    }

    // 解析表达式
    MutiTerm term = parse_expression(expr);

    // 显示存储方式
    if(term.type == LINKLIST) {
        printf("使用链表存储（稀疏多项式）\n");
    } else {
        printf("使用顺序表存储（密集多项式）\n");
    }

    return term;
}

int main() {
    printf("============= 多项式运算程序 =============\n\n");

    int input_method;
    printf("请选择多项式输入方式：\n");
    printf("1. 数字形式 (输入系数和指数)\n");
    printf("2. 表达式形式 (如：2x^3 + 3x^4 + x^2)\n");
    printf("请选择 (1 或 2)：");
    scanf("%d", &input_method);

    // 创建第一个多项式
    printf("\n创建第一个多项式：\n");
    MutiTerm m1;
    if (input_method == 1) {
        m1 = create_multiterm_numeric();
    } else if (input_method == 2) {
        m1 = create_multiterm_expression();
    } else {
        printf("无效的选择，默认使用数字形式输入\n");
        m1 = create_multiterm_numeric();
    }

    // 创建第二个多项式
    printf("\n创建第二个多项式：\n");
    MutiTerm m2;
    if (input_method == 1) {
        m2 = create_multiterm_numeric();
    } else if (input_method == 2) {
        m2 = create_multiterm_expression();
    } else {
        printf("无效的选择，默认使用数字形式输入\n");
        m2 = create_multiterm_numeric();
    }

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
                printf("结果多项式使用顺序表存储（稠密多项式）\n");
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
                printf("结果多项式使用顺序表存储（稠密多项式）\n");
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
                printf("结果多项式使用顺序表存储（稠密多项式）\n");
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