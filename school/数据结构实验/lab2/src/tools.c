#include "tools.h"
#include <stddef.h>

// 安全释放函数
status nfree(any *_ptr){
    if(*_ptr==NULL) return WARRING;
    free(*_ptr);
    *_ptr=NULL;
    return SUCCESS;
}