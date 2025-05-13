#include "interface.h"
#include "tools.h"
#include <stdarg.h>
#include <stdlib.h>

// 初始化接口列表
interfaces new_interfaces(Byte subnums,...){
    // 第一个字节存储数量，后面存储接口表
    interfaces res=(interfaces)malloc(sizeof(InterFaces)+subnums*sizeof(interface));
    if(res==NULL) return NULL;
    // 设置数量
    res->count=subnums;
    // 设置接口
    va_list args;
    va_start(args,subnums);
    for(Byte i=0;i<subnums;i++){
        res->inters[i]=va_arg(args,interface);
    }
    va_end(args);
    return res;
}
// 获取元素大小
// size_t inters_size(interfaces self,Byte index){
//     if (self == NULL) return 0;
//     if (index >= self->count) return 0;
//     return self->inters[index]->_itemSize;
// }
// 获取子接口
// interface inters_sub(interfaces self,Byte index){
//     if (self == NULL) return NULL;
//     if (index >= self->count) return NULL;
//     return self->inters[index];
// }
Exception free_interfaces(interfaces self){
    if(self==NULL) return new_exception(WARRING,"free_interfaces: 传入self指针为空!");
    Exception e=new_exception(SUCCESS,"");
    // 释放接口列表
    for(Byte i=0;i<self->count;i++){
        exception_pass(&e,free_interface(self->inters[i]));
    }
    free(self);
    return e;
}

interface new_interface(size_t itemSize,interfaces subinters,string format,...){
    interface self = (interface)malloc(sizeof(struct InterFace));
    if (self == NULL) return NULL;
    self->_itemSize = itemSize;
    self->_subInters=subinters;
    // self->_subNums=visitp_cast(byte,subinters)[-1];
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
            case 'p': self->print = func; break;
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
    if(self->_subInters!=NULL) exception_pass(&e,free_interfaces(self->_subInters));
    // status_down(&res,nfree((any *)&self));
    exception_down(&e,sfree(self));
    return e;
}

// size_t inter_size(interface self){
//     if (self == NULL) return 0;
//     return self->_itemSize;
// }