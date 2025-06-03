#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 生成随机数据
void generate_random_data(SqList *L, int count) {
    L->length = count;
    srand((unsigned int)time(NULL));

    for (int i = 1; i <= count; i++) {
        L->r[i].key = rand() % 100 + 1; // 生成1-100的随机数
        L->r[i].otherinfo = i; // 用于验证稳定性的原始位置
    }
}

// 生成有序数据
void generate_sorted_data(SqList *L, int count, int ascending) {
    L->length = count;

    for (int i = 1; i <= count; i++) {
        if (ascending) {
            L->r[i].key = i; // 升序数据
        } else {
            L->r[i].key = count - i + 1; // 降序数据
        }
        L->r[i].otherinfo = i; // 用于验证稳定性的原始位置
    }
}

// 生成逆序数据
void generate_reverse_data(SqList *L, int count) {
    generate_sorted_data(L, count, 0); // 生成降序数据
}

// 生成含重复元素的数据
void generate_duplicate_data(SqList *L, int count) {
    L->length = count;
    srand((unsigned int)time(NULL));

    for (int i = 1; i <= count; i++) {
        L->r[i].key = rand() % 5 + 1; // 生成1-5的随机数，增加重复概率
        L->r[i].otherinfo = i; // 用于验证稳定性的原始位置
    }
}

// 获取数据输入选择
int get_data_input_choice() {
    int choice;
    printf("1. 手动输入数据\n");
    printf("2. 随机生成数据\n");
    printf("3. 生成已排序数据（升序）\n");
    printf("4. 生成已排序数据（降序）\n");
    printf("5. 生成含重复元素数据\n");
    printf("请选择数据输入方式 (1-5): ");

    if (scanf("%d", &choice) != 1) {
        choice = 1; // 默认手动输入
    }

    return choice;
}

// 根据选择获取数据
void get_data_by_choice(SqList *L) {
    int choice = get_data_input_choice();
    int count;

    if (choice == 1) {
        // 手动输入数据
        printf("请输入要排序的元素个数 (1-%d): ", MAXSIZE);
        if (scanf("%d", &count) != 1 || count <= 0 || count > MAXSIZE) {
            printf("输入无效，设置为默认值10\n");
            count = 10;
        }

        L->length = count;
        printf("请输入 %d 个整数: ", count);
        for (int i = 1; i <= count; i++) {
            if (scanf("%d", &L->r[i].key) != 1) {
                L->r[i].key = i; // 如果输入失败，使用默认值
            }
            L->r[i].otherinfo = i; // 用于验证稳定性的原始位置
        }
    } else {
        // 自动生成数据
        printf("请输入要生成的元素个数 (1-%d): ", MAXSIZE);
        if (scanf("%d", &count) != 1 || count <= 0 || count > MAXSIZE) {
            printf("输入无效，设置为默认值10\n");
            count = 10;
        }

        switch (choice) {
            case 2:
                printf("正在生成 %d 个随机数据...\n", count);
                generate_random_data(L, count);
                break;
            case 3:
                printf("正在生成 %d 个升序数据...\n", count);
                generate_sorted_data(L, count, 1);
                break;
            case 4:
                printf("正在生成 %d 个降序数据...\n", count);
                generate_sorted_data(L, count, 0);
                break;
            case 5:
                printf("正在生成 %d 个含重复元素的数据...\n", count);
                generate_duplicate_data(L, count);
                break;
            default:
                printf("无效选择，生成随机数据\n");
                generate_random_data(L, count);
                break;
        }
    }
}
