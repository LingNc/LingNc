#ifndef UTILS_H
#define UTILS_H

#include "redtype.h"
#include "sqlist.h"
// 数据生成相关函数声明
void generate_random_data(sqlist L, int count);
void generate_sorted_data(sqlist L, int count, int ascending);
void generate_reverse_data(sqlist L, int count);
void generate_duplicate_data(sqlist L, int count);

// 输入输出相关函数声明
int get_data_input_choice();
void get_data_by_choice(sqlist L);

#endif // UTILS_H
