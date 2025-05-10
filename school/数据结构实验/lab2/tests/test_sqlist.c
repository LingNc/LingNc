#include "sqlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 整数类型的接口函数
any int_init(self obj, interface subinter) {
    // 初始化为0
    *(int*)obj = 0;
    return NULL;
}

any int_clear(self obj) {
    // 清除操作（对整数没有特殊处理）
    return NULL;
}

any int_free(self obj) {
    // 释放操作（对整数没有特殊处理）
    return NULL;
}

int main() {
    printf("开始测试顺序表...\n");

    // 创建整数类型的接口
    interface int_interface = new_interface(sizeof(int), NULL, "ilf", int_init, int_clear, int_free);
    if (int_interface == NULL) {
        printf("接口创建失败！\n");
        return 1;
    }

    // 创建顺序表
    sqlist list = new_sqlist(int_interface);
    if (list == NULL) {
        printf("顺序表创建失败！\n");
        free_interface(int_interface);
        return 1;
    }

    printf("顺序表初始化成功，初始大小: %zu\n", sqlist_size(list));

    // 测试添加元素
    printf("测试添加元素...\n");
    for (int i = 0; i < 15; i++) {
        int num = i * 10;
        Exception e = sqlist_push_back(list, &num);
        if (e.status != SUCCESS) {
            printf("添加元素失败: %s\n", e.msg);
            break;
        }
    }

    // 显示所有元素
    printf("顺序表现有元素 (大小: %zu):\n", sqlist_size(list));
    for (int i = 0; i < sqlist_size(list); i++) {
        int* val = (int*)sqlist_at(list, i);
        printf("[%d] = %d\n", i, *val);
    }

    // 测试弹出元素
    printf("\n测试弹出元素...\n");
    for (int i = 0; i < 5; i++) {
        Exception e = sqlist_pop_back(list);
        if (e.status != SUCCESS) {
            printf("弹出元素失败: %s\n", e.msg);
            break;
        }
    }

    // 再次显示所有元素
    printf("弹出后顺序表现有元素 (大小: %zu):\n", sqlist_size(list));
    for (int i = 0; i < sqlist_size(list); i++) {
        int* val = (int*)sqlist_at(list, i);
        printf("[%d] = %d\n", i, *val);
    }

    // 测试迭代器
    printf("\n测试迭代器...\n");
    sqlist_iterator iter = sqlist_begin(list);
    if (iter == NULL) {
        printf("迭代器创建失败！\n");
    } else {
        printf("使用迭代器遍历顺序表:\n");
        for (int i = 0; i < sqlist_size(list); i++) {
            int* val = sqlist_iterator_visit(iter);
            printf("[%d] = %d\n", i, *val);
            iter->next(iter);
        }
        free_sqlist_iterator(iter);
    }

    // 清空顺序表并释放资源
    Exception clear_e = sqlist_clear(list);
    if (clear_e.status != SUCCESS) {
        printf("顺序表清空失败: %s\n", clear_e.msg);
    } else {
        printf("\n顺序表已清空，大小: %zu\n", sqlist_size(list));
    }

    // 释放顺序表
    Exception free_e = free_sqlist(list);
    if (free_e.status != SUCCESS) {
        printf("顺序表释放失败: %s\n", free_e.msg);
    } else {
        printf("顺序表已释放\n");
    }

    // 释放接口
    Exception interface_e = free_interface(int_interface);
    if (interface_e.status != SUCCESS) {
        printf("接口释放失败: %s\n", interface_e.msg);
    } else {
        printf("接口已释放\n");
    }

    // ========== 顺序表指针唯一性与浅拷贝检测 ==========
    printf("\n===== 测试顺序表指针唯一性与浅拷贝问题 =====\n");
    typedef struct { int val; } BoxedInt;
    interface boxedint_interface = new_interface(sizeof(BoxedInt), NULL, "icm", NULL, NULL, NULL);
    sqlist ptrlist = new_sqlist(boxedint_interface);
    BoxedInt *ptrs[5];
    for (int i = 0; i < 5; ++i) {
        ptrs[i] = malloc(sizeof(BoxedInt));
        ptrs[i]->val = i * 10;
        sqlist_push_back(ptrlist, ptrs[i]);
    }
    void *addrs[5];
    for (int i = 0; i < 5; ++i) {
        BoxedInt *p = (BoxedInt*)sqlist_at(ptrlist, i);
        addrs[i] = p;
    }
    int unique = 1;
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            if (addrs[i] == addrs[j]) unique = 0;
        }
    }
    if (unique) {
        printf("顺序表所有指针唯一，无浅拷贝问题。\n");
    } else {
        printf("[警告] 顺序表存在浅拷贝/指针复用问题！\n");
    }
    for (int i = 0; i < 5; ++i) free(ptrs[i]);
    free_sqlist(ptrlist);
    free_interface(boxedint_interface);

    printf("测试完成！\n");
    return 0;
}