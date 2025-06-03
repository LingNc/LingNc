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

// 栈结构用于非递归快速排序
struct Stack{
    int data[MAXSIZE * 2];
    KeyType top;
};
typedef struct Stack Stack;
typedef Stack *stack;

// 函数声明
sqlist new_sqlist();
void sqlist_input_data(sqlist L);
void sqlist_print(sqlist L,const char *title);
void sqlist_copy(sqlist src,sqlist dest);
int check_stability(sqlist original, sqlist sorted);

// 排序算法函数声明
void simple_selection_sort(sqlist L, sortstats stats);
void direct_insertion_sort(sqlist L, sortstats stats);
void bubble_sort(sqlist L, sortstats stats);
void binary_insertion_sort(sqlist L, sortstats stats);
void shell_sort(sqlist L, sortstats stats);
void quick_sort(sqlist L, sortstats stats);
void quick_sort_recursive(sqlist L, int low, int high, sortstats stats);
void quick_sort_non_recursive(sqlist L, sortstats stats);
void heap_sort(sqlist L, sortstats stats);

// 辅助函数
void swap(redtype a, redtype b, sortstats stats);
int binary_search(sqlist L, RedType elem, int low, int high, sortstats stats);
void heapify(sqlist L, int start, int end, sortstats stats);
void build_max_heap(sqlist L, sortstats stats);

#endif //SQLIST_H