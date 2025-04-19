#include <stdio.h>
#include "sqlist.h"
#include "linklist.h"

// 测试顺序表
void test_sqlist() {
    printf("\n===== 测试顺序表 =====\n");

    // 创建顺序表
    sqlist list = new_sqlist();
    if (list == NULL) {
        printf("创建顺序表失败\n");
        return;
    }

    // 添加元素
    printf("添加元素：");
    for (int i = 0; i < 10; i++) {
        sqlist_push_back(list, i * 10);
        printf("%d ", i * 10);
    }
    printf("\n");

    // 显示顺序表长度和容量
    printf("顺序表长度：%ld\n", sqlist_lenth(list));
    printf("顺序表容量：%ld\n", sqlist_size(list));

    // 显示所有元素
    printf("顺序表元素：");
    for (size_t i = 0; i < sqlist_lenth(list); i++) {
        printf("%d ", sqlist_get(list, i));
    }
    printf("\n");

    // 在索引3的位置插入元素
    printf("在索引3的位置插入元素35\n");
    sqlist_insert(list, 3, 35);

    // 显示所有元素
    printf("插入后顺序表元素：");
    for (size_t i = 0; i < sqlist_lenth(list); i++) {
        printf("%d ", sqlist_get(list, i));
    }
    printf("\n");

    // 删除索引5的元素
    printf("删除索引5的元素\n");
    sqlist_delete(list, 5);

    // 显示所有元素
    printf("删除后顺序表元素：");
    for (size_t i = 0; i < sqlist_lenth(list); i++) {
        printf("%d ", sqlist_get(list, i));
    }
    printf("\n");

    // 测试尾部弹出
    printf("尾部弹出一个元素\n");
    sqlist_pop_back(list);

    // 显示所有元素
    printf("弹出后顺序表元素：");
    for (size_t i = 0; i < sqlist_lenth(list); i++) {
        printf("%d ", sqlist_get(list, i));
    }
    printf("\n");

    // 释放顺序表
    sqlist_free(list);
    printf("顺序表已释放\n");
}

// 测试链表
void test_linklist() {
    printf("\n===== 测试链表 =====\n");

    // 创建链表
    linklist list = new_linklist();
    if (list == NULL) {
        printf("创建链表失败\n");
        return;
    }

    // 添加元素
    printf("添加元素：");
    for (int i = 0; i < 10; i++) {
        linklist_push_back(list, i * 10);
        printf("%d ", i * 10);
    }
    printf("\n");

    // 显示链表长度
    printf("链表长度：%ld\n", linklist_length(list));

    // 显示所有元素
    printf("链表元素：");
    for (size_t i = 0; i < linklist_length(list); i++) {
        printf("%d ", linklist_get(list, i));
    }
    printf("\n");

    // 头部插入元素
    printf("头部插入元素5\n");
    linklist_push_front(list, 5);

    // 显示所有元素
    printf("头插后链表元素：");
    for (size_t i = 0; i < linklist_length(list); i++) {
        printf("%d ", linklist_get(list, i));
    }
    printf("\n");

    // 删除索引3的元素
    printf("删除索引3的元素\n");
    linklist_delete(list, 3);

    // 显示所有元素
    printf("删除后链表元素：");
    for (size_t i = 0; i < linklist_length(list); i++) {
        printf("%d ", linklist_get(list, i));
    }
    printf("\n");

    // 测试查找
    int search_value = 50;
    printf("查找值为%d的元素\n", search_value);
    node found = linklist_find(list, search_value);
    if (found != NULL) {
        printf("找到元素：%d\n", found->data);
    } else {
        printf("未找到元素\n");
    }

    // 测试尾部弹出
    printf("尾部弹出一个元素\n");
    linklist_pop_back(list);

    // 显示所有元素
    printf("弹出后链表元素：");
    for (size_t i = 0; i < linklist_length(list); i++) {
        printf("%d ", linklist_get(list, i));
    }
    printf("\n");

    // 释放链表
    linklist_free(list);
    printf("链表已释放\n");
}

int main() {
    printf("数据结构实验一：线性表的实现与应用\n");

    // 测试顺序表
    test_sqlist();

    // 测试链表
    test_linklist();

    return 0;
}