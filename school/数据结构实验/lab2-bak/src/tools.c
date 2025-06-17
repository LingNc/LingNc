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

// 移动函数
bool mmove(any _dest,any _src,interface _inter){
    if(_dest==NULL||_src==NULL||_inter==NULL) return false;
    if(_inter->move)
        _inter->move(_dest,_src);
    else if(_inter->copy){
        _inter->copy(_dest,_src);
        if(_inter->clear) _inter->clear(_src);
    }
    else{
        smove(_dest,_src,_inter->_itemSize);
    }
    return true;
}
// 值移动函数
bool smove(any _dest,any _src,size_t _size){
    if(_dest==NULL||_src==NULL) return false;
    memcpy(_dest,_src,_size);
    memset(_src,0,_size);
    return true;
}
// 移动转换函数
any move(any _src,interface _inter){
    if(_src==NULL||_inter==NULL) return NULL;
    any res=malloc(_inter->_itemSize);
    if(res==NULL) return NULL;
    if(_inter->move)
        _inter->move(res,_src);
    else if(_inter->copy){
        _inter->copy(res,_src);
        if(_inter->clear) _inter->clear(_src);
    }
    else{
        memcpy(res,_src,_inter->_itemSize);
        memset(_src,0,_inter->_itemSize);
    }
    return res;
}
// 指针交换函数
bool pswap(any *a, any *b){
    any temp = *a;
    *a = *b;
    *b = temp;
    return true;
}
// 移动交换
bool mswap(any a,any b,interface inter){
    if(a==NULL||b==NULL||inter==NULL) return false;
    if(inter->move){
        any t=malloc(inter->_itemSize);
        if(t==NULL) return false;
        inter->move(t,a);
        inter->move(a,b);
        inter->move(b,t);
        return true;
    }
    else
        return sswap(a,b,inter_size(inter));
}
// 浅拷贝交换函数
bool sswap(any a,any b,size_t size){
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
bool dswap(any a,any b,interface inter){
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

// 二分查找函数
any bsearchf(any key,any base,size_t nmemb,size_t size,bool(*check)(any,any)){
    if(key==NULL||base==NULL||check==NULL) return NULL;
    pointer(size) p=base;
    size_t l=0,r=nmemb;
    while (l < r) {
        size_t mid = l + ((r - l)>>1);
        if(check(key,p[mid])) r=mid;
        else l=mid+1;
    }
    return (l==nmemb)?NULL:p[l];
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
        *res = b;
    }
    else if ((b & 0b11100000) == 0b11000000){
        len = 2;
        if (pos + len > max) return (int)(pos - max);
        *res = ((b & 0x1F) << 6) | (buffer[pos + 1] & 0x3F);
    }
    else if ((b & 0b11110000) == 0b11100000){
        len = 3;
        if (pos + len > max) return (int)(pos - max);
        *res = ((b & 0x0F) << 12) | ((buffer[pos + 1] & 0x3F) << 6) | (buffer[pos + 2] & 0x3F);
    }
    else if ((b & 0b11111000) == 0b11110000){
        len = 4;
        if (pos + len > max) return (int)(pos - max);
        *res = ((b & 0x07) << 18) | ((buffer[pos + 1] & 0x3F) << 12) |
               ((buffer[pos + 2] & 0x3F) << 6) | (buffer[pos + 3] & 0x3F);
    }
    else{
        // 非法编码 替换为 U+FFFD 替换字符
        *res = 0xFFFD;
        return 1;
    }

    return len;
}