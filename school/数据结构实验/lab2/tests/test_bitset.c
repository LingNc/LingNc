#include "bitset.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("==== Bitset 功能测试 ====");
    size_t size = 20;
    bitset bs = new_bitset(size);
    if (!bs) {
        printf("\n[错误] bitset 创建失败！\n");
        return 1;
    }
    printf("\n[1] 创建 bitset，大小: %zu\n", size);
    bitset_print(bs);

    // 测试 set/get
    printf("[2] 测试 set/get ...\n");
    for (size_t i = 0; i < size; ++i) {
        bitset_set(bs, i, i % 2);
    }
    printf("设置后 bitset: ");
    bitset_print(bs);
    int ok = 1;
    for (size_t i = 0; i < size; ++i) {
        if (bitset_get(bs, i) != (i % 2)) {
            printf("[错误] bitset_get(%zu) 结果错误！\n", i);
            ok = 0;
        }
    }
    if (ok) printf("get/set 功能正常\n");

    // 测试 clear
    printf("[3] 测试 clear ...\n");
    bitset_clear(bs);
    int allzero = 1;
    for (size_t i = 0; i < size; ++i) {
        if (bitset_get(bs, i)) allzero = 0;
    }
    if (allzero) printf("clear 功能正常\n");
    else printf("[错误] clear 功能异常\n");
    bitset_print(bs);

    // 测试 copy
    printf("[4] 测试 copy ...\n");
    for (size_t i = 0; i < size; ++i) bitset_set(bs, i, 1);
    bitset bs2 = new_bitset(size);
    bitset_copy(bs2, bs);
    int same = 1;
    for (size_t i = 0; i < size; ++i) {
        if (bitset_get(bs2, i) != 1) same = 0;
    }
    if (same) printf("copy 功能正常\n");
    else printf("[错误] copy 功能异常\n");
    bitset_print(bs2);

    // 测试越界
    printf("[5] 测试越界 ...\n");
    size_t out_index = size + 100;
    if (!bitset_get(bs, out_index)) printf("越界 get 返回安全\n");


    // 测试越界写入（在合理范围内自动扩容）
    printf("[6] 测试越界写入扩容 ...\n");
    size_t expand_index = size + 10; // 小幅越界，应该自动扩容
    bitset_set(bs, expand_index, 1);
    if (bitset_get(bs, expand_index) == 1) {
        printf("小幅越界写入/读取正常（自动扩容）\n");
    } else {
        printf("[错误] 小幅越界写入/读取失败！\n");
    }
    // 测试极大越界（超过最大范围）
    printf("[7] 测试极大越界写入 ...\n");
    size_t big_out_index = BITSET_MAX_SIZE + 100;
    bitset_set(bs, big_out_index, 1); // 应有报错
    if (!bitset_get(bs, big_out_index)) {
        printf("极大越界写入后读取安全（未写入）\n");
    } else {
        printf("[警告] 极大越界写入后读取为1，需检查实现！\n");
    }

    // 释放
    free_bitset(bs);
    free_bitset(bs2);
    printf("\n==== Bitset 测试完成 ====");
    return 0;
}
