#include "tools.h"
#include <stddef.h>

// 安全释放函数
status nfree(any *_ptr){
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