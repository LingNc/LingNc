#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// 复制HuffCode结构体定义
typedef uint8_t Byte;
struct HuffCode{
    uint64_t _code;
    Byte _size;
};
typedef struct HuffCode HuffCode;
typedef HuffCode *huffcode;

// 测试函数
void test_huffcode_display() {
    printf("=== 测试霍夫曼编码显示 ===\n");

    // 模拟一些编码值
    HuffCode codes[] = {
        {0, 1},  // 0
        {1, 1},  // 1
        {0, 2},  // 00
        {1, 2},  // 01
        {2, 2},  // 10
        {3, 2},  // 11
        {0, 3},  // 000
        {1, 3},  // 001
        {2, 3},  // 010
        {3, 3},  // 011
        {4, 3},  // 100
        {5, 3},  // 101
        {6, 3},  // 110
        {7, 3},  // 111
    };

    for (int i = 0; i < 14; i++) {
        printf("编码值: %lu, 长度: %u -> ", codes[i]._code, codes[i]._size);

        // 从左到右显示位
        for (Byte j = 0; j < codes[i]._size; j++) {
            // 从最高有效位开始
            Byte bit_pos = codes[i]._size - 1 - j;
            bool bit = (codes[i]._code >> bit_pos) & 1;
            printf("%d", bit ? 1 : 0);
        }
        printf("\n");
    }
}

int main() {
    test_huffcode_display();
    return 0;
}
