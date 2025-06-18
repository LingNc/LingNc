#include <stdio.h>
#include "include/tools.h"

int main() {
    printf("测试UTF-8解析...\n");

    // 测试简单ASCII字符
    unsigned char buffer[] = {'a', 'b', 'c', '\n'};
    utf8 ch;

    for (int i = 0; i < 4; i++) {
        int len = read_utf8(&ch, buffer, i, 4);
        printf("位置%d: 字节0x%02X -> UTF8字符%lu, 长度%d\n", i, buffer[i], ch, len);
    }

    return 0;
}
