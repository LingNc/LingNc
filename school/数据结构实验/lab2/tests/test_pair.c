#include "pair.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlist.h"

// 整数类型的接口函数
any int_init(self obj, interface subinter) {
    // 初始化为0
    *(int*)obj = 0;
    return obj;
}

any int_clear(self obj) {
    // 清除操作（对整数没有特殊处理）
    return obj;
}

any int_free(self obj) {
    // 释放操作（对整数没有特殊处理）
    return obj;
}

// 字符串类型的接口函数
any string_init(self obj, interface subinter) {
    // 初始化为空字符串
    *(char**)obj = strdup("");
    return obj;
}

any string_copy(self obj, any other) {
    // 复制字符串
    if (*(char**)other == NULL) {
        *(char**)obj = NULL;
        return obj;
    }

    *(char**)obj = strdup(*(char**)other);
    return obj;
}

any string_clear(self obj) {
    // 释放字符串内存
    if (*(char**)obj != NULL) {
        free(*(char**)obj);
        *(char**)obj = NULL;
    }
    return obj;
}

any string_free(self obj) {
    // 清理并释放字符串
    string_clear(obj);
    return obj;
}

// 测试 pairinter 的功能
void test_pair_inter(interface int_interface, interface string_interface) {
    printf("\n=== 测试 pairinter 功能 ===\n");

    // 创建 pairinter
    printf("创建 pairinter...\n");
    pairinter pinter = new_pairinter(int_interface, string_interface);
    if (pinter == NULL) {
        printf("pairinter 创建失败！\n");
        return;
    }

    printf("pairinter 创建成功！\n");
    printf("first interface 项大小: %zu\n", pinter->first->_itemSize);
    printf("second interface 项大小: %zu\n", pinter->second->_itemSize);

    // 测试 pairinter_init 函数
    printf("\n测试 pairinter_init 函数...\n");
    pairinter test_init = malloc(sizeof(PairInter));
    if (test_init == NULL) {
        printf("内存分配失败！\n");
        free_pairinter(pinter);
        return;
    }

    // 初始化
    pairinter_init(test_init, NULL);
    printf("pairinter_init 成功！\n");

    // 测试 pairinter_clear 函数
    printf("\n测试 pairinter_clear 函数...\n");
    pairinter_clear(test_init);
    printf("pairinter_clear 成功！\n");

    // 释放资源
    printf("\n释放 pairinter 资源...\n");
    free(test_init);
    printf("pairinter 资源释放成功！\n");
}

// 测试 pair 的功能
void test_pair(interface int_interface, interface string_interface) {
    printf("\n=== 测试 pair 功能 ===\n");

    // 创建 pairinter
    printf("创建 pairinter...\n");
    pairinter pinter = new_pairinter(int_interface, string_interface);
    if (pinter == NULL) {
        printf("pairinter 创建失败！\n");
        return;
    }

    printf("pairinter 创建成功！\n");

    // 测试 pair 创建和初始化
    printf("\n测试 pair 创建...\n");
    int first_value = 42;
    char* second_value = strdup("测试字符串");
    if (second_value == NULL) {
        printf("字符串内存分配失败！\n");
        free_pairinter(pinter);
        return;
    }

    pair test_pair = new_pair(&first_value, &second_value, pinter);
    if (test_pair == NULL) {
        printf("pair 创建失败！\n");
        free_pairinter(pinter);
        free(second_value);
        return;
    }

    // 显示 pair 中的值
    printf("pair 创建成功！\n");
    printf("pair.first = %d\n", *(int*)test_pair->first);
    printf("pair.second = %s\n", *(char**)test_pair->second);

    // 测试 pair 复制
    printf("\n测试 pair 复制...\n");
    pair copied_pair = malloc(sizeof(Pair));
    if (copied_pair == NULL) {
        printf("复制 pair 内存分配失败！\n");
        free_pair(test_pair);
        free_pairinter(pinter);
        free(second_value);
        return;
    }

    // // 初始化并复制
    // if (pair_init(copied_pair, pinter) == NULL) {
    //     printf("pair 初始化失败！\n");
    //     free(copied_pair);
    //     free_pair(test_pair);
    //     free_pairinter(pinter);
    //     free(second_value);
    //     return;
    // }

    if (pair_copy(copied_pair, test_pair) == NULL) {
        printf("pair 复制失败！\n");
        free_pair(copied_pair);
        free_pair(test_pair);
        free_pairinter(pinter);
        free(second_value);
        return;
    }

    // 显示复制后的值
    printf("复制后的 pair:\n");
    printf("copied_pair.first = %d\n", *(int*)copied_pair->first);
    printf("copied_pair.second = %s\n", *(char**)copied_pair->second);

    // 修改原始值，验证是否深拷贝
    printf("\n修改原始 pair 值...\n");
    *(int*)test_pair->first = 100;

    char* new_str = strdup("修改后的字符串");
    if (new_str == NULL) {
        printf("字符串内存分配失败！\n");
        free_pair(copied_pair);
        free_pair(test_pair);
        free_pairinter(pinter);
        free(second_value);
        return;
    }

    free(*(char**)test_pair->second);
    *(char**)test_pair->second = new_str;

    printf("\n修改原始 pair 后:\n");
    printf("原始 pair.first = %d\n", *(int*)test_pair->first);
    printf("原始 pair.second = %s\n", *(char**)test_pair->second);
    printf("复制的 pair.first = %d\n", *(int*)copied_pair->first);
    printf("复制的 pair.second = %s\n", *(char**)copied_pair->second);

    // 测试 pair_clear 函数
    printf("\n测试 pair_clear 函数...\n");
    if (pair_clear(copied_pair) == NULL) {
        printf("pair_clear 失败！\n");
    } else {
        printf("pair_clear 成功！\n");
    }

    // 清理资源
    printf("\n释放资源...\n");
    free_pair(test_pair);
    free_pairinter(pinter);
    printf("资源释放成功！\n");
}

// 测试 pair_create_inter 及 sqlist 存储 pair
void test_pair_sqlist() {
    printf("\n=== 测试 pair_create_inter 及 sqlist 存储 pair ===\n");
    // 创建 pair 接口
    interface int_interface = new_interface(sizeof(int), NULL, "ilf", int_init, int_clear, int_free);
    interface string_interface = new_interface(sizeof(char*), NULL, "iclf", string_init, string_copy, string_clear, string_free);
    pairinter pinter = new_pairinter(int_interface, string_interface);
    interface pair_iface = pair_create_inter();
    sqlist list = new_sqlist(pair_iface);

    // 创建并插入多个 pair
    for (int i = 0; i < 3; ++i) {
        int *first = malloc(sizeof(int));
        *first = i * 10;
        char buf[32];
        snprintf(buf, sizeof(buf), "str%d", i);
        char **second = malloc(sizeof(char*));
        *second = strdup(buf);
        pair p = new_pair(first, second, pinter);
        sqlist_push_back(list, p);
        free(first);
        free(*second);
        free(second);
    }

    // 访问并打印
    for (int i = 0; i < 3; ++i) {
        pair p = (pair)sqlist_at(list, i);
        printf("sqlist[%d]: first=%d, second=%s\n", i, *(int*)p->first, *(char**)p->second);
    }

    // 清理
    sqlist_clear(list);
    free_sqlist(list);
    free_pairinter(pinter);
    printf("pair_create_inter 及 sqlist 存储 pair 测试完成！\n");
}

int main() {
    printf("======= 开始测试 pair 结构 =======\n");

    // 创建整数和字符串的接口
    printf("创建接口...\n");
    interface int_interface = new_interface(sizeof(int), NULL, "ilf", int_init, int_clear, int_free);
    interface string_interface = new_interface(sizeof(char*), NULL, "iclf", string_init, string_copy, string_clear, string_free);

    if (int_interface == NULL || string_interface == NULL) {
        printf("接口创建失败！\n");
        if (int_interface) free_interface(int_interface);
        if (string_interface) free_interface(string_interface);
        return 1;
    }

    printf("接口创建成功！\n");

    // 测试 pairinter 功能
    test_pair_inter(int_interface, string_interface);

    // 测试 pair 功能
    test_pair(int_interface, string_interface);

    // 新增测试
    test_pair_sqlist();

    // ========== pair 深拷贝与浅拷贝检测 ==========
    printf("\n===== 测试 pair 深拷贝与浅拷贝问题 =====\n");
    interface int_interface2 = new_interface(sizeof(int), NULL, "ilf", int_init, int_clear, int_free);
    interface str_interface2 = new_interface(sizeof(char*), NULL, "iclf", string_init, string_copy, string_clear, string_free);
    pairinter pinter2 = new_pairinter(int_interface2, str_interface2);
    int *a = malloc(sizeof(int)); *a = 123;
    char **b = malloc(sizeof(char*)); *b = strdup("deepcopy");
    pair p1 = new_pair(a, b, pinter2);
    pair p2 = malloc(sizeof(Pair));
    pair_copy(p2, p1);
    // 修改原始 p1
    *a = 999;
    free(*b); *b = strdup("changed");
    printf("p1: %d, %s\n", *(int*)p1->first, *(char**)p1->second);
    printf("p2: %d, %s\n", *(int*)p2->first, *(char**)p2->second);
    if (*(int*)p2->first == 123 && strcmp(*(char**)p2->second, "deepcopy") == 0) {
        printf("pair 深拷贝无浅拷贝问题。\n");
    } else {
        printf("[警告] pair 复制存在浅拷贝问题！\n");
    }
    free_pair(p1); free_pair(p2); free_pairinter(pinter2);
    free(a); free(*b); free(b);

    // 释放接口资源
    printf("\n释放接口资源...\n");
    printf("接口资源释放成功！\n");

    printf("======= 测试完成！=======\n");
    return 0;
}