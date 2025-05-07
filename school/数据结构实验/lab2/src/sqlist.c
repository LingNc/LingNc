#include "sqlist.h"
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// 状态退化函数
status status_down(status *self,status new_status){
    if(new_status<*self) *self=new_status;
    return *self;
}

// 安全释放函数
status nfree(any _ptr){
    if(_ptr==NULL) return WARRING;
    free(_ptr);
    _ptr=NULL;
    return SUCCESS;
}

// 异常处理

exception new_exception(status status,string msg){
    exception self = (exception)malloc(sizeof(struct Exception));
    if (self == NULL) {
        return NULL;
    }
    self->_status = status;
    self->_msg = msg;
    return self;
}

exception pass_exception(exception self,string new_msg){
    exception new_e=new_exception(self->_status,NULL);
#   ifndef STRING_H
    size_t new_size=strlen(self->_status)+strlen(new_msg);
    string temp_str=malloc(new_size*sizeof(char));
    strcat(temp_str,new_msg);
    strcat(temp_str,self->_msg);
#   endif
    return new_e;
}

status exception_get(exception self){
    return self->_status;
}

status free_exception(exception self){
    status res=SUCCESS;
    if(self==NULL) status_down(&res,WARRING);
    status_down(&res,nfree(self->_msg));
    status_down(&res,nfree(self));
    return res;
}

interface new_interface(size_t itemSize,...){
    interface self=(interface)malloc(sizeof(struct InterFace));
    if (self == NULL) return NULL;
    va_list args;
    va_start(args, itemSize);
    self->_itemSize=itemSize;

    any temp;
    temp=va_arg(args,new_func);
    if(temp==inter_end) goto end;
    self->new=temp;
    temp=va_arg(args,free_func);
    if(temp==inter_end) goto end;
    self->free=temp;
end:
    va_end(args);
    return self;
}

exception free_interface(interface self){
    status res=SUCCESS;
    if(self==NULL) status_down(&res,WARRING);
    status_down(&res,nfree(self));
    return res;
}

