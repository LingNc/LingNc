#include "menu.h"

int main() {
    int choice;

    printf("欢迎使用内部排序算法模拟系统！\n");
    printf("本系统实现了8种常用的内部排序算法，并提供性能测试功能。\n");
    printf("数据格式说明：输出中的数字格式为 key(original_pos)，用于验证稳定性。\n");

    while (1) {
        display_menu();
        scanf("%d", &choice);

        if (choice == 0) {
            printf("感谢使用，再见！\n");
            break;
        } else if (choice == 9) {
            performance_test();
        } else if (choice >= 1 && choice <= 8) {
            test_sort_algorithm(choice);
        } else {
            printf("无效的选择，请重新输入！\n");
        }

        printf("\n按回车键继续...");
        getchar(); // 消耗换行符
        getchar(); // 等待用户按回车
    }

    return 0;
}