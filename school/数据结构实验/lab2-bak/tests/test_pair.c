#include "pair.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlist.h"
#include "interface.h"

// 整数类型的接口函数
any int_init(self obj, interfaces subinters) {
    *(int*)obj = 0;
    return obj;
}
any int_copy(self obj, any other) {
    *(int*)obj = *(int*)other;
    return obj;
}
any int_clear(self obj) {
    return obj;
}
any int_free(self obj) {
    return obj;
}
void int_print(self obj) {
    printf("%d", *(int*)obj);
}

// 字符串类型的接口函数
any string_init(self obj, interfaces subinters) {
    *(char**)obj = strdup("");
    return obj;
}
any string_copy(self obj, any other) {
    if (*(char**)other == NULL) {
        *(char**)obj = NULL;
        return obj;
    }
    *(char**)obj = strdup(*(char**)other);
    return obj;
}
any string_clear(self obj) {
    if (*(char**)obj != NULL) {
        free(*(char**)obj);
        *(char**)obj = NULL;
    }
    return obj;
}
any string_free(self obj) {
    string_clear(obj);
    return obj;
}
void string_print(self obj) {
    if (*(char**)obj)
        printf("%s", *(char**)obj);
    else
        printf("(null)");
}

void test_pair_interface() {
    printf("\n=== 测试新版 pair 接口 ===\n");
    // 创建 int/string 接口
    interface int_iface = new_interface(sizeof(int), NULL, "iclfp", int_init, int_copy, int_clear, int_free, int_print);
    interface str_iface = new_interface(sizeof(char*), NULL, "iclfp", string_init, string_copy, string_clear, string_free, string_print);
    interfaces pair_inters = new_interfaces(2, int_iface, str_iface);
    // 创建 pair
    int a = 10;
    char *b = strdup("hello");
    pair p = new_pair(&a, &b, pair_inters);
    printf("pair.first = "); int_print(p->first); printf(", pair.second = "); string_print(p->second); printf("\n");
    // 拷贝 pair
    pair p2 = malloc(sizeof(Pair));
    pair_copy(p2, p);
    printf("拷贝后 pair2: first = "); int_print(p2->first); printf(", second = "); string_print(p2->second); printf("\n");
    // 修改原始 pair
    *(int*)p->first = 99;
    free(*(char**)p->second); *(char**)p->second = strdup("world");
    printf("修改后原始 pair: first = "); int_print(p->first); printf(", second = "); string_print(p->second); printf("\n");
    printf("拷贝后 pair2: first = "); int_print(p2->first); printf(", second = "); string_print(p2->second); printf("\n");
    // 清理
    free_pair(p);
    free_pair(p2);
    free_interfaces(pair_inters);
    free_interface(int_iface);
    free_interface(str_iface);
    free(b);
}

int main() {
    printf("======= 开始测试 pair 结构 =======\n");
    test_pair_interface();
    printf("======= 测试完成！=======\n");
    return 0;
}