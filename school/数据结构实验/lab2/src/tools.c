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
// 指针交换函数
bool pswap(any *a, any *b){
    any temp = *a;
    *a = *b;
    *b = temp;
    return true;
}
// 浅拷贝交换函数
bool sswap(const any a,const any b,size_t size){
    if (a == NULL || b == NULL || size == 0) return false;
    any temp = malloc(size);
    if (temp == NULL) return false;
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
    return true;
}
// 深拷贝交换函数
bool dswap(const any a,const any b,interface inter){
    if (a == NULL || b == NULL) return false;
    if (inter == NULL) return false;
    if (inter->copy == NULL){
        // 如果没有拷贝函数，直接交换
        sswap(a, b,inter->_itemSize);
        return true;
    }
    else{
        // 如果有拷贝函数，使用拷贝函数交换
        any temp = malloc(inter->_itemSize);
        if (temp == NULL) return false;
        inter->copy(temp, a);
        inter->copy(a, b);
        inter->copy(b, temp);
        free(temp);
    }
    return true;
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