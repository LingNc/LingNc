#ifndef SQLIST_H
#define SQLIST_H

#include <redtype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 顺序表
struct SqList{
    RedType  r[MAXSIZE+1];
    int      length; /*参加排序元素的实际个数*/
};
typedef struct SqList SqList;
typedef SqList *sqlist;

// 函数声明
void init_list(SqList *L);
void input_data(SqList *L);
void print_list(SqList *L, const char *title);
void copy_list(SqList *src, SqList *dest);
int check_stability(SqList *original, SqList *sorted);

// 排序算法函数声明
void simple_selection_sort(SqList *L, SortStats *stats);
void direct_insertion_sort(SqList *L, SortStats *stats);
void bubble_sort(SqList *L, SortStats *stats);
void binary_insertion_sort(SqList *L, SortStats *stats);
void shell_sort(SqList *L, SortStats *stats);
void quick_sort(SqList *L, SortStats *stats);
void quick_sort_recursive(SqList *L, int low, int high, SortStats *stats);
void quick_sort_non_recursive(SqList *L, SortStats *stats);
void heap_sort(SqList *L, SortStats *stats);

// 辅助函数
void swap(RedType *a, RedType *b, SortStats *stats);
int binary_search(SqList *L, RedType elem, int low, int high, SortStats *stats);
void heapify(SqList *L, int start, int end, SortStats *stats);
void build_max_heap(SqList *L, SortStats *stats);

// 菜单相关
void display_menu();
void test_sort_algorithm(int choice);
void performance_test();

#endif //SQLIST_H