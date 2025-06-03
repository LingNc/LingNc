#include "sqlist.h"

// 初始化顺序表
void init_list(SqList *L) {
    L->length = 0;
    memset(L->r, 0, sizeof(L->r));
}

// 手动输入数据（保留用于兼容性）
void input_data(SqList *L) {
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
void print_list(SqList *L, const char *title) {
    printf("%s", title);
    if (strlen(title) > 0) printf(": ");
    for (int i = 1; i <= L->length; i++) {
        printf("%d(%d) ", L->r[i].key, L->r[i].otherinfo);
    }
    printf("\n");
}

// 复制顺序表
void copy_list(SqList *src, SqList *dest) {
    dest->length = src->length;
    for (int i = 0; i <= src->length; i++) {
        dest->r[i] = src->r[i];
    }
}

// 检查排序稳定性
int check_stability(SqList *original, SqList *sorted) {
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
void swap(RedType *a, RedType *b, SortStats *stats) {
    if (a != b) {
        RedType temp = *a;
        *a = *b;
        *b = temp;
        stats->move_count += 3; // 一次交换算3次移动
    }
}

// 1. 简单选择排序
void simple_selection_sort(SqList *L, SortStats *stats) {
    stats->compare_count = 0;
    stats->move_count = 0;

    printf("\n简单选择排序过程:\n");
    print_list(L, "初始状态");

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
        print_list(L, "");
    }
}

// 2. 直接插入排序
void direct_insertion_sort(SqList *L, SortStats *stats) {
    stats->compare_count = 0;
    stats->move_count = 0;

    printf("\n直接插入排序过程:\n");
    print_list(L, "初始状态");

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
        print_list(L, "");
    }
}

// 3. 冒泡排序
void bubble_sort(SqList *L, SortStats *stats) {
    stats->compare_count = 0;
    stats->move_count = 0;

    printf("\n冒泡排序过程:\n");
    print_list(L, "初始状态");

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
        print_list(L, "");
        if (!flag) break; // 如果没有交换，说明已经有序
    }
}

// 二分查找插入位置
int binary_search(SqList *L, RedType elem, int low, int high, SortStats *stats) {
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
void binary_insertion_sort(SqList *L, SortStats *stats) {
    stats->compare_count = 0;
    stats->move_count = 0;

    printf("\n折半插入排序过程:\n");
    print_list(L, "初始状态");

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
        print_list(L, "");
    }
}

// 5. 希尔排序
void shell_sort(SqList *L, SortStats *stats) {
    stats->compare_count = 0;
    stats->move_count = 0;

    printf("\n希尔排序过程:\n");
    print_list(L, "初始状态");

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
        print_list(L, "");
        gap /= 2;
    }
}

// 快速排序的分割函数
int partition(SqList *L, int low, int high, SortStats *stats) {
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
void quick_sort_recursive(SqList *L, int low, int high, SortStats *stats) {
    if (low < high) {
        int pivot_pos = partition(L, low, high, stats);
        printf("划分结果");
        print_list(L, "");

        quick_sort_recursive(L, low, pivot_pos - 1, stats);
        quick_sort_recursive(L, pivot_pos + 1, high, stats);
    }
}

void quick_sort(SqList *L, SortStats *stats) {
    stats->compare_count = 0;
    stats->move_count = 0;

    printf("\n快速排序（递归）过程:\n");
    print_list(L, "初始状态");

    quick_sort_recursive(L, 1, L->length, stats);
}

// 栈结构用于非递归快速排序
typedef struct {
    int data[MAXSIZE * 2];
    int top;
} Stack;

void push(Stack *s, int value) {
    s->data[++s->top] = value;
}

int pop(Stack *s) {
    return s->data[s->top--];
}

int is_empty(Stack *s) {
    return s->top == -1;
}

// 7. 快速排序（非递归）
void quick_sort_non_recursive(SqList *L, SortStats *stats) {
    stats->compare_count = 0;
    stats->move_count = 0;

    printf("\n快速排序（非递归）过程:\n");
    print_list(L, "初始状态");

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
            print_list(L, "");

            push(&s, low);
            push(&s, pivot_pos - 1);
            push(&s, pivot_pos + 1);
            push(&s, high);
        }
    }
}

// 堆调整
void heapify(SqList *L, int start, int end, SortStats *stats) {
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
void build_max_heap(SqList *L, SortStats *stats) {
    for (int i = L->length / 2; i >= 1; i--) {
        heapify(L, i, L->length, stats);
    }
}

// 8. 堆排序
void heap_sort(SqList *L, SortStats *stats) {
    stats->compare_count = 0;
    stats->move_count = 0;

    printf("\n堆排序过程:\n");
    print_list(L, "初始状态");

    // 建立最大堆
    build_max_heap(L, stats);
    printf("建堆后");
    print_list(L, "");

    // 排序
    for (int i = L->length; i >= 2; i--) {
        swap(&L->r[1], &L->r[i], stats);
        heapify(L, 1, i - 1, stats);
        printf("第%d趟", L->length - i + 1);
        print_list(L, "");
    }
}