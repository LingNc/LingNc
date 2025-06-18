#include <stdio.h>
#include <string.h>
#include "../include/tools.h"

int main() {
    printf("测试UTF-8编码处理...\n");

    // 测试é字符的UTF-8编码：c3 a9
    unsigned char test_bytes[] = {0xc3, 0xa9};
    utf8 ch;
    
    int len = read_utf8(&ch, test_bytes, 0, 2);
    printf("UTF-8字节 [c3 a9] -> Unicode: U+%04lX, 长度: %d\n", ch, len);
    
    // 验证这是否是é (U+00E9 = 233)
    if (ch == 0x00E9) {
        printf("✓ 正确读取了é字符\n");
    } else {
        printf("✗ 读取错误，期望U+00E9，实际U+%04lX\n", ch);
    }

    // 测试UTF-8重构
    printf("\n测试UTF-8重构...\n");
    unsigned char utf8_bytes[4];
    int out_len = 0;

    if (ch <= 0x7F) {
        utf8_bytes[0] = (unsigned char)ch;
        out_len = 1;
    } else if (ch <= 0x7FF) {
        utf8_bytes[0] = (unsigned char)(0xC0 | (ch >> 6));
        utf8_bytes[1] = (unsigned char)(0x80 | (ch & 0x3F));
        out_len = 2;
    } else if (ch <= 0xFFFF) {
        utf8_bytes[0] = (unsigned char)(0xE0 | (ch >> 12));
        utf8_bytes[1] = (unsigned char)(0x80 | ((ch >> 6) & 0x3F));
        utf8_bytes[2] = (unsigned char)(0x80 | (ch & 0x3F));
        out_len = 3;
    } else {
        utf8_bytes[0] = (unsigned char)(0xF0 | (ch >> 18));
        utf8_bytes[1] = (unsigned char)(0x80 | ((ch >> 12) & 0x3F));
        utf8_bytes[2] = (unsigned char)(0x80 | ((ch >> 6) & 0x3F));
        utf8_bytes[3] = (unsigned char)(0x80 | (ch & 0x3F));
        out_len = 4;
    }

    printf("Unicode U+%04lX -> UTF-8字节: ", ch);
    for (int i = 0; i < out_len; i++) {
        printf("%02x ", utf8_bytes[i]);
    }
    printf("(长度: %d)\n", out_len);

    // 比较原始和重构的字节
    bool match = true;
    if (out_len == 2) {
        if (utf8_bytes[0] != 0xc3 || utf8_bytes[1] != 0xa9) {
            match = false;
        }
    } else {
        match = false;
    }

    if (match) {
        printf("✓ UTF-8重构正确\n");
    } else {
        printf("✗ UTF-8重构错误\n");
    }

    return 0;
}
