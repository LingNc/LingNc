#ifndef UTILS_H
#define UTILS_H

#include "redtype.h"
#include "sqlist.h"
// 数据生成相关函数声明
void generate_random_data(SqList *L, int count);
void generate_sorted_data(SqList *L, int count, int ascending);
void generate_reverse_data(SqList *L, int count);
void generate_duplicate_data(SqList *L, int count);

// 输入输出相关函数声明
int get_data_input_choice();
void get_data_by_choice(SqList *L);

#endif // UTILS_H
