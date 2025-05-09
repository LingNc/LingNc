#include "interface.h"
#include "tools.h"
#include <stdarg.h>
#include <stdlib.h>

interface new_interface(size_t itemSize, any subinter, string format, ...) {
    interface self = (interface)malloc(sizeof(struct InterFace));
    if (self == NULL) return NULL;
    self->_itemSize = itemSize;
    self->_subinter = subinter;

    va_list args;
    va_start(args, format);

    // 初始化所有函数指针为 NULL
    self->init = NULL;
    self->copy = NULL;
    self->clear = NULL;
    self->cmp = NULL;
    self->free = NULL;

    // 按 format 字符串顺序设置函数指针
    for (const char *p = format; p && *p; ++p) {
        any func = va_arg(args, any);
        switch (*p) {
            case 'i': self->init = func; break;
            case 'c': self->copy = func; break;
            case 'l': self->clear = func; break;
            case 'm': self->cmp = func; break;
            case 'f': self->free = func; break;
            default: break; // 未知字符忽略
        }
    }

    va_end(args);
    return self;
}

Exception free_interface(interface self){
    status res=SUCCESS;
    if(self==NULL){
        status_down(&res,WARRING);
        return new_exception(res,"free_interface: 传入self指针为空!");
    }
    Exception e=new_exception(res,"");
    if(self->_subinter!=NULL) exception_pass(&e,free_interface(self->_subinter));
    // status_down(&res,nfree((any *)&self));
    exception_down(&e,sfree(&self));
    free(self);
    return e;
}
size_t inter_item_size(interface self){
    if(self==NULL) return 0;
    return self->_itemSize;
}