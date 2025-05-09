#include "tools.h"
#include <string.h>
#include <stdlib.h>

// 安全释放函数
status pfree(any* _ptr){
    if (*_ptr == NULL) return WARRING;
    free(*_ptr);
    *_ptr = NULL;
    return SUCCESS;
}
// 任意变量交换函数
void swap(size_t itemSize, any a, any b){
    any t = malloc(itemSize);
    memcpy(t, a, itemSize);
    memcpy(a, b, itemSize);
    memcpy(b, t, itemSize);
    free(t);
}
// utf8 读取
int read_utf8(utf8* res, byte buffer, size_t pos, size_t max){
    if (buffer == NULL || pos >= max) return 0;
    // 读取 utf8 第一个字节
    Byte b = buffer[pos];
    // 辨别是多长的代码
    int len = 0;
    if ((b & 0b10000000) == 0){
        len = 1;
    }
    else if ((b & 0b11100000) == 0b11000000){
        len = 2;
    }
    else if ((b & 0b11110000) == 0b11100000){
        len = 3;
    }
    else if ((b & 0b11111000) == 0b11110000){
        len = 4;
    }
    else{
        // 非法编码 替换为 U+FFFD 替换字符
        *res = 0xFFFD;
        return 1;
    }
    // 检查缓冲区是否足够
    if (pos + len > max){
        // 需要回退到pos，重新读取缓冲区
        return (int)(pos - max);
    }
    *res = 0;
    for (int i = 0; i < len; i++){
        *res <<= 8;
        *res |= buffer[pos + i];
    }
    return len;
}