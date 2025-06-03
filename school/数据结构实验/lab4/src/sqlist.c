#include "sqlist.h"

// 创建新的顺序表，返回指针
sqlist new_sqlist() {
    sqlist L = (sqlist)malloc(sizeof(SqList));
    if (L == NULL) {
        printf("内存分配失败!\n");
        exit(1);
    }
    L->length = 0;
    memset(L->r, 0, sizeof(L->r));
    return L;
}

// 输入数据
void sqlist_input_data(sqlist L) {
    printf("请输入要排序的元素个数 (1-%d): ", MAXSIZE);
    scanf("%d", &L->length);

    if (L->length <= 0 || L->length > MAXSIZE) {
        printf("输入的元素个数不合法！\n");
        L->length = 0;
        return;
    }

    printf("请输入%d个整数: ", L->length);
    for (int i = 1; i <= L->length; i++) {
        scanf("%d", &L->r[i].key);
        L->r[i].otherinfo = i; // 记录原始位置，用于稳定性检测
    }
}

// 打印顺序表
void sqlist_print(sqlist L, const char *title) {
    printf("%s", title);
    if (strlen(title) > 0) printf(": ");
    for (int i = 1; i <= L->length; i++) {
        printf("%d(%d) ", L->r[i].key, L->r[i].otherinfo);
    }
    printf("\n");
}

// 复制顺序表
void sqlist_copy(sqlist src, sqlist dest) {
    dest->length = src->length;
    for (int i = 0; i <= src->length; i++) {
        dest->r[i] = src->r[i];
    }
}

// 检查排序稳定性
int check_stability(sqlist original, sqlist sorted) {
    (void)original; // 避免未使用参数警告
    for (int i = 1; i < sorted->length; i++) {
        for (int j = i + 1; j <= sorted->length; j++) {
            if (sorted->r[i].key == sorted->r[j].key) {
                if (sorted->r[i].otherinfo > sorted->r[j].otherinfo) {
                    return 0; // 不稳定
                }
            }
        }
    }
    return 1; // 稳定
}

// 交换两个元素
void swap(redtype a, redtype b, sortstats stats) {
    if (a != b) {
        RedType temp = *a;
        *a = *b;
        *b = temp;
        stats->move_count += 3; // 一次交换算3次移动
    }
}

// 1. 简单选择排序
void simple_selection_sort(sqlist L, sortstats stats) {
    stats->compare_count = 0;
    stats->move_count = 0;

    printf("\n简单选择排序过程:\n");
    sqlist_print(L, "初始状态");

    for (int i = 1; i < L->length; i++) {
        int min_idx = i;
        for (int j = i + 1; j <= L->length; j++) {
            stats->compare_count++;
            if (L->r[j].key < L->r[min_idx].key) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&L->r[i], &L->r[min_idx], stats);
        }
        printf("第%d趟", i);
        sqlist_print(L, "");
    }
}

// 2. 直接插入排序
void direct_insertion_sort(sqlist L, sortstats stats) {
    stats->compare_count = 0;
    stats->move_count = 0;

    printf("\n直接插入排序过程:\n");
    sqlist_print(L, "初始状态");

    for (int i = 2; i <= L->length; i++) {
        L->r[0] = L->r[i]; // 哨兵
        stats->move_count++;

        int j = i - 1;
        while (L->r[0].key < L->r[j].key) {
            stats->compare_count++;
            L->r[j + 1] = L->r[j];
            stats->move_count++;
            j--;
        }
        if (j >= 0) stats->compare_count++; // 最后一次比较

        L->r[j + 1] = L->r[0];
        stats->move_count++;

        printf("第%d趟", i - 1);
        sqlist_print(L, "");
    }
}

// 3. 冒泡排序
void bubble_sort(sqlist L, sortstats stats) {
    stats->compare_count = 0;
    stats->move_count = 0;

    printf("\n冒泡排序过程:\n");
    sqlist_print(L, "初始状态");

    for (int i = 1; i < L->length; i++) {
        int flag = 0; // 标记是否发生交换
        for (int j = 1; j <= L->length - i; j++) {
            stats->compare_count++;
            if (L->r[j].key > L->r[j + 1].key) {
                swap(&L->r[j], &L->r[j + 1], stats);
                flag = 1;
            }
        }
        printf("第%d趟", i);
        sqlist_print(L, "");
        if (!flag) break; // 如果没有交换，说明已经有序
    }
}

// 二分查找插入位置
int binary_search(sqlist L, RedType elem, int low, int high, sortstats stats) {
    while (low <= high) {
        stats->compare_count++;
        int mid = (low + high) / 2;
        if (elem.key < L->r[mid].key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

// 4. 折半插入排序
void binary_insertion_sort(sqlist L, sortstats stats) {
    stats->compare_count = 0;
    stats->move_count = 0;

    printf("\n折半插入排序过程:\n");
    sqlist_print(L, "初始状态");

    for (int i = 2; i <= L->length; i++) {
        L->r[0] = L->r[i]; // 哨兵
        stats->move_count++;

        int pos = binary_search(L, L->r[0], 1, i - 1, stats);

        for (int j = i - 1; j >= pos; j--) {
            L->r[j + 1] = L->r[j];
            stats->move_count++;
        }

        L->r[pos] = L->r[0];
        stats->move_count++;

        printf("第%d趟", i - 1);
        sqlist_print(L, "");
    }
}

// 5. 希尔排序
void shell_sort(sqlist L, sortstats stats) {
    stats->compare_count = 0;
    stats->move_count = 0;

    printf("\n希尔排序过程:\n");
    sqlist_print(L, "初始状态");

    int gap = L->length / 2;
    int round = 1;

    while (gap >= 1) {
        printf("增量 gap = %d:\n", gap);

        for (int i = gap + 1; i <= L->length; i++) {
            L->r[0] = L->r[i];
            stats->move_count++;

            int j = i - gap;
            while (j > 0 && L->r[0].key < L->r[j].key) {
                stats->compare_count++;
                L->r[j + gap] = L->r[j];
                stats->move_count++;
                j -= gap;
            }
            if (j > 0) stats->compare_count++;

            L->r[j + gap] = L->r[0];
            stats->move_count++;
        }

        printf("第%d轮", round++);
        sqlist_print(L, "");
        gap /= 2;
    }
}

// 快速排序的分割函数
int partition(sqlist L, int low, int high, sortstats stats) {
    RedType pivot = L->r[low];
    stats->move_count++;

    while (low < high) {
        while (low < high && L->r[high].key >= pivot.key) {
            stats->compare_count++;
            high--;
        }
        if (low < high) stats->compare_count++;

        L->r[low] = L->r[high];
        stats->move_count++;

        while (low < high && L->r[low].key <= pivot.key) {
            stats->compare_count++;
            low++;
        }
        if (low < high) stats->compare_count++;

        L->r[high] = L->r[low];
        stats->move_count++;
    }

    L->r[low] = pivot;
    stats->move_count++;

    return low;
}

// 6. 快速排序（递归）
void quick_sort_recursive(sqlist L, int low, int high, sortstats stats) {
    if (low < high) {
        int pivot_pos = partition(L, low, high, stats);
        printf("划分结果");
        sqlist_print(L, "");

        quick_sort_recursive(L, low, pivot_pos - 1, stats);
        quick_sort_recursive(L, pivot_pos + 1, high, stats);
    }
}

void quick_sort(sqlist L, sortstats stats) {
    stats->compare_count = 0;
    stats->move_count = 0;

    printf("\n快速排序（递归）过程:\n");
    sqlist_print(L, "初始状态");

    quick_sort_recursive(L, 1, L->length, stats);
}

void push(stack s, int value) {
    s->data[++s->top] = value;
}

int pop(stack s) {
    return s->data[s->top--];
}

int is_empty(stack s) {
    return s->top == -1;
}

// 7. 快速排序（非递归）
void quick_sort_non_recursive(sqlist L, sortstats stats) {
    stats->compare_count = 0;
    stats->move_count = 0;

    printf("\n快速排序（非递归）过程:\n");
    sqlist_print(L, "初始状态");

    Stack s;
    s.top = -1;

    push(&s, 1);
    push(&s, L->length);

    while (!is_empty(&s)) {
        int high = pop(&s);
        int low = pop(&s);

        if (low < high) {
            int pivot_pos = partition(L, low, high, stats);
            printf("划分结果");
            sqlist_print(L, "");

            push(&s, low);
            push(&s, pivot_pos - 1);
            push(&s, pivot_pos + 1);
            push(&s, high);
        }
    }
}

// 堆调整
void heapify(sqlist L, int start, int end, sortstats stats) {
    int parent = start;
    int child = 2 * parent;

    while (child <= end) {
        stats->compare_count++;
        if (child + 1 <= end && L->r[child].key < L->r[child + 1].key) {
            child++;
        }

        stats->compare_count++;
        if (L->r[parent].key >= L->r[child].key) {
            break;
        } else {
            swap(&L->r[parent], &L->r[child], stats);
            parent = child;
            child = 2 * parent;
        }
    }
}

// 建立最大堆
void build_max_heap(sqlist L, sortstats stats) {
    for (int i = L->length / 2; i >= 1; i--) {
        heapify(L, i, L->length, stats);
    }
}

// 8. 堆排序
void heap_sort(sqlist L, sortstats stats) {
    stats->compare_count = 0;
    stats->move_count = 0;

    printf("\n堆排序过程:\n");
    sqlist_print(L, "初始状态");

    // 建立最大堆
    build_max_heap(L, stats);
    printf("建堆后");
    sqlist_print(L, "");

    // 排序
    for (int i = L->length; i >= 2; i--) {
        swap(&L->r[1], &L->r[i], stats);
        heapify(L, 1, i - 1, stats);
        printf("第%d趟", L->length - i + 1);
        sqlist_print(L, "");
    }
}