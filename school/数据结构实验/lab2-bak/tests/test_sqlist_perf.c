#include "sqlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 整数类型的接口函数
any int_init(self obj, interface subinter) {
    *(int*)obj = 0;
    return NULL;
}
any int_clear(self obj) { return NULL; }
any int_free(self obj) { return NULL; }

#define N 1000000  // 测试数据量，可根据需要调整

int main() {
    printf("\n===== sqlist 性能测试 =====\n");
    interface int_interface = new_interface(sizeof(int), NULL, "ilf", int_init, int_clear, int_free);
    if (int_interface == NULL) {
        printf("接口创建失败！\n");
        return 1;
    }
    sqlist list = new_sqlist(int_interface);
    if (list == NULL) {
        printf("顺序表创建失败！\n");
        free_interface(int_interface);
        return 1;
    }

    clock_t t1, t2;
    double elapsed;

    // 插入性能测试
    t1 = clock();
    for (int i = 0; i < N; i++) {
        int num = i;
        Exception e = sqlist_push_back(list, &num);
        if (e.status != SUCCESS) {
            printf("插入失败: %s\n", e.msg);
            break;
        }
    }
    t2 = clock();
    elapsed = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("插入 %d 个元素耗时: %.3f 秒\n", N, elapsed);

    // 顺序访问性能测试
    long long sum = 0;
    t1 = clock();
    for (int i = 0; i < N; i++) {
        int* val = (int*)sqlist_at(list, i);
        sum += *val;
    }
    t2 = clock();
    elapsed = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("顺序访问 %d 个元素耗时: %.3f 秒 (sum=%lld)\n", N, elapsed, sum);

    // 删除性能测试
    t1 = clock();
    for (int i = 0; i < N; i++) {
        Exception e = sqlist_pop_back(list);
        if (e.status != SUCCESS) {
            printf("删除失败: %s\n", e.msg);
            break;
        }
    }
    t2 = clock();
    elapsed = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("删除 %d 个元素耗时: %.3f 秒\n", N, elapsed);

    free_sqlist(list);
    free_interface(int_interface);
    printf("===== 性能测试结束 =====\n");
    return 0;
}
