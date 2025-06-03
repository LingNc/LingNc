#include "menu.h"
#include "utils.h"
#include <stdio.h>

// 显示主菜单
void display_menu() {
    printf("\n==================== 内部排序算法模拟系统 ====================\n");
    printf("1. 简单选择排序\n");
    printf("2. 直接插入排序\n");
    printf("3. 冒泡排序\n");
    printf("4. 折半插入排序\n");
    printf("5. 希尔排序\n");
    printf("6. 快速排序（递归）\n");
    printf("7. 快速排序（非递归）\n");
    printf("8. 堆排序\n");
    printf("9. 性能对比测试\n");
    printf("0. 退出\n");
    printf("============================================================\n");
    printf("请选择排序算法 (0-9): ");
}

// 测试排序算法
void test_sort_algorithm(int choice) {
    SqList original_list, test_list;
    SortStats stats;

    init_list(&original_list);
    printf("\n请选择数据输入方式或输入要排序的数据:\n");
    get_data_by_choice(&original_list);

    if (original_list.length == 0) {
        printf("数据输入失败！\n");
        return;
    }

    printf("\n原始数据: ");
    print_list(&original_list, "");

    copy_list(&original_list, &test_list);

    const char* algorithm_names[] = {
        "", "简单选择排序", "直接插入排序", "冒泡排序", "折半插入排序",
        "希尔排序", "快速排序（递归）", "快速排序（非递归）", "堆排序"
    };

    printf("\n正在执行 %s...\n", algorithm_names[choice]);

    switch (choice) {
        case 1:
            simple_selection_sort(&test_list, &stats);
            break;
        case 2:
            direct_insertion_sort(&test_list, &stats);
            break;
        case 3:
            bubble_sort(&test_list, &stats);
            break;
        case 4:
            binary_insertion_sort(&test_list, &stats);
            break;
        case 5:
            shell_sort(&test_list, &stats);
            break;
        case 6:
            quick_sort(&test_list, &stats);
            break;
        case 7:
            quick_sort_non_recursive(&test_list, &stats);
            break;
        case 8:
            heap_sort(&test_list, &stats);
            break;
        default:
            printf("无效的选择！\n");
            return;
    }

    printf("\n排序结果: ");
    print_list(&test_list, "");
    printf("比较次数: %d\n", stats.compare_count);
    printf("移动次数: %d\n", stats.move_count);
    printf("稳定性: %s\n", check_stability(&original_list, &test_list) ? "稳定" : "不稳定");
}

// 性能对比测试
void performance_test() {
    printf("\n==================== 性能对比测试 ====================\n");

    SqList original_list, test_list;
    SortStats stats;

    init_list(&original_list);
    printf("请选择测试数据:\n");
    get_data_by_choice(&original_list);

    if (original_list.length == 0) {
        printf("数据输入失败！\n");
        return;
    }

    printf("\n测试数据: ");
    print_list(&original_list, "");

    const char* algorithms[] = {
        "简单选择排序", "直接插入排序", "冒泡排序", "折半插入排序",
        "希尔排序", "快速排序（递归）", "快速排序（非递归）", "堆排序"
    };

    void (*sort_functions[])(SqList*, SortStats*) = {
        simple_selection_sort, direct_insertion_sort, bubble_sort, binary_insertion_sort,
        shell_sort, quick_sort, quick_sort_non_recursive, heap_sort
    };

    printf("\n性能对比结果:\n");
    printf("%-20s %-10s %-10s %-10s\n", "算法名称", "比较次数", "移动次数", "稳定性");
    printf("----------------------------------------------------------------\n");

    for (int i = 0; i < 8; i++) {
        copy_list(&original_list, &test_list);
        sort_functions[i](&test_list, &stats);

        printf("%-20s %-10d %-10d %-10s\n",
               algorithms[i],
               stats.compare_count,
               stats.move_count,
               check_stability(&original_list, &test_list) ? "稳定" : "不稳定");
    }
}
