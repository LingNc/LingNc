#include "tools.h"
#include <string.h>
#include <stdlib.h>

// 安全释放函数
status pfree(any *_ptr){
    if(*_ptr==NULL) return WARRING;
    free(*_ptr);
    *_ptr=NULL;
    return SUCCESS;
}
// 任意变量交换函数
void swap(size_t itemSize,any a,any b){
    any t=malloc(itemSize);
    memcpy(t,a,itemSize);
    memcpy(a,b,itemSize);
    memcpy(b,t,itemSize);
    free(t);
}
// utf8 读取
size_t read_utf8(utf8* res,byte buffer,size_t pos,size_t max){
    if(buffer==NULL||pos>=max) return ERROR;
    // 读取一个字节
    Byte b=buffer[pos];
    // 计算字节长度
    size_t len=0;
    if((b&0b10000000)==0){
        len=1;
    }else if((b&0b11100000)==0b11000000){
        len=2;
    }else if((b&0b11110000)==0b11100000){
        len=3;
    }else if((b&0b11111000)==0b11110000){
        len=4;
    }
    else{
        // 无效编码 替换为 U+FFFD
        *res|=0xFFFD;
        return 1;
    }
    // 读取utf8
    *res=0;
    for(size_t i=0;i<len;i++){
        *res<<=8;
        *res|=buffer[pos+i];
    }
    return len;
}