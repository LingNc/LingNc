// filepath: /home/lingnc/LingNc/school/数据结构实验/lab2/tests/test_heap.c
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 整数类型的接口函数
any int_init(self obj, interface subinter) {
    // 初始化为0
    *(int*)obj = 0;
    return NULL;
}

// 整数的复制函数
any int_copy(self obj, any data) {
    // 复制整数值
    *(int*)obj = *(int*)data;
    return NULL;
}

// 整数比较函数
bool int_cmp(any a, any b) {
    // 比较两个整数是否相等
    return *(int*)a == *(int*)b;
}

// 比较函数 - 最小堆 (返回1表示a<b，即a应该排在b前面)
bool int_min_cmp(any a, any b) {
    return *(int*)a < *(int*)b;
}

// 比较函数 - 最大堆 (返回1表示a>b，即a应该排在b前面)
bool int_max_cmp(any a, any b) {
    return *(int*)a > *(int*)b;
}

int main() {
    printf("开始测试堆结构...\n");

    // 创建整数类型的接口
    // 码表 i:init c:copy l:clear m:cmp f:free
    interface int_interface = new_interface(sizeof(int), NULL, "icm", int_init, int_copy, int_cmp);
    if (int_interface == NULL) {
        printf("接口创建失败！\n");
        return 1;
    }

    // 测试最小堆
    printf("\n===== 测试最小堆 =====\n");
    heap min_heap = new_heap(int_interface, int_min_cmp);
    if (min_heap == NULL) {
        printf("最小堆创建失败！\n");
        free_interface(int_interface);
        return 1;
    }

    // 添加元素到最小堆
    printf("向最小堆添加元素...\n");
    int test_data[] = {30, 10, 50, 20, 40, 70, 60};
    for (int i = 0; i < 7; i++) {
        printf("添加 %d\n", test_data[i]);
        Exception e = heap_push(min_heap, &test_data[i]);
        if (e.status != SUCCESS) {
            printf("添加元素失败: %s\n", e.msg);
            break;
        }
    }

    // 显示堆的大小
    printf("最小堆大小: %zu\n", heap_size(min_heap));

    // 测试堆的弹出操作
    printf("\n从最小堆弹出元素 (应该按升序弹出):\n");
    while (!heap_empty(min_heap)) {
        int* top = (int*)heap_top(min_heap);
        if (top != NULL) {
            printf("弹出: %d\n", *top);
        } else {
            printf("堆顶为空！\n");
            break;
        }
        Exception e = heap_pop(min_heap);
        if (e.status != SUCCESS) {
            printf("弹出元素失败: %s\n", e.msg);
            break;
        }
    }

    // 测试堆的清空操作
    Exception clear_e = heap_clear(min_heap);
    if (clear_e.status != SUCCESS) {
        printf("最小堆清空失败: %s\n", clear_e.msg);
    } else {
        printf("最小堆已清空，大小: %zu\n", heap_size(min_heap));
    }

    // 释放最小堆
    Exception free_e = free_heap(min_heap);
    if (free_e.status != SUCCESS) {
        printf("最小堆释放失败: %s\n", free_e.msg);
    } else {
        printf("最小堆已释放\n");
    }

    // 测试最大堆
    printf("\n===== 测试最大堆 =====\n");
    heap max_heap = new_heap(int_interface, int_max_cmp);
    if (max_heap == NULL) {
        printf("最大堆创建失败！\n");
        free_interface(int_interface);
        return 1;
    }

    // 添加元素到最大堆
    printf("向最大堆添加元素...\n");
    for (int i = 0; i < 7; i++) {
        printf("添加 %d\n", test_data[i]);
        Exception e = heap_push(max_heap, &test_data[i]);
        if (e.status != SUCCESS) {
            printf("添加元素失败: %s\n", e.msg);
            break;
        }
    }

    // 显示堆的大小
    printf("最大堆大小: %zu\n", heap_size(max_heap));

    // 测试堆的弹出操作
    printf("\n从最大堆弹出元素 (应该按降序弹出):\n");
    while (!heap_empty(max_heap)) {
        int* top = (int*)heap_top(max_heap);
        if (top != NULL) {
            printf("弹出: %d\n", *top);
        } else {
            printf("堆顶为空！\n");
            break;
        }
        Exception e = heap_pop(max_heap);
        if (e.status != SUCCESS) {
            printf("弹出元素失败: %s\n", e.msg);
            break;
        }
    }

    // 测试从现有列表创建堆
    printf("\n===== 测试从现有列表创建堆 =====\n");
    sqlist list = new_sqlist(int_interface);
    if (list == NULL) {
        printf("列表创建失败！\n");
        free_interface(int_interface);
        return 1;
    }

    // 添加元素到列表
    for (int i = 0; i < 7; i++) {
        Exception e = sqlist_push_back(list, &test_data[i]);
        if (e.status != SUCCESS) {
            printf("添加元素到列表失败: %s\n", e.msg);
            break;
        }
    }

    // 从列表创建堆
    heap heap_from_list = new_heap_from(list, int_min_cmp);
    if (heap_from_list == NULL) {
        printf("从列表创建堆失败！\n");
        free_sqlist(list);
        free_interface(int_interface);
        return 1;
    }

    printf("从列表创建堆成功，堆大小: %zu\n", heap_size(heap_from_list));

    // 测试从现有列表创建的堆的弹出操作
    printf("\n从创建的堆弹出元素 (应该按升序弹出):\n");
    while (!heap_empty(heap_from_list)) {
        int* top = (int*)heap_top(heap_from_list);
        if (top != NULL) {
            printf("弹出: %d\n", *top);
        } else {
            printf("堆顶为空！\n");
            break;
        }
        Exception e = heap_pop(heap_from_list);
        if (e.status != SUCCESS) {
            printf("弹出元素失败: %s\n", e.msg);
            break;
        }
    }

    // 释放资源
    free_heap(heap_from_list);
    free_sqlist(list);
    free_interface(int_interface);

    printf("\n测试完成！\n");
    return 0;
}