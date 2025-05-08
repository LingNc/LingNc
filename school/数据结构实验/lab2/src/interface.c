#include "interface.h"
#include "tools.h"
#include <stdarg.h>
#include <stdlib.h>

interface new_interface(size_t itemSize,interface subinter,...){
    interface self=(interface)malloc(sizeof(struct InterFace));
    if(self==NULL) return NULL;
    va_list args;
    self->_itemSize=itemSize;
    self->_subinter=subinter;
    va_start(args,subinter);
    any temp;
    temp=va_arg(args,init_func);
    if(temp==inter_end) goto end;
    self->init=temp;
    temp=va_arg(args,copy_func);
    if(temp==inter_end) goto end;
    self->copy=temp;
    temp=va_arg(args,clear_func);
    if(temp==inter_end) goto end;
    self->clear=temp;
    temp=va_arg(args,cmp_func);
    if(temp==inter_end) goto end;
    self->cmp=temp;
    temp=va_arg(args,free_func);
    if(temp==inter_end) goto end;
    self->free=temp;
end:
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
    exception_down(&e,nfree((any *)&self));
    return e;
}
size_t inter_item_size(interface self){
    if(self==NULL) return 0;
    return self->_itemSize;
}