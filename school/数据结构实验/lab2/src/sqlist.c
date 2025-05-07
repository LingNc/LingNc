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

Exception new_exception(status status,string msg){
    Exception self;
    self.status=status;
    self.msg=msg;
    return self;
}

Exception exception_pass(exception self,string new_msg){
    if(self==NULL){
        return new_exception(ERROR,"exception_add: 传入self指针为空!");
    }
    status res=SUCCESS;
    status_down(&res,self->status);
    // 计算大小
#   ifndef STRING_H
    size_t msgSize=strlen(self->msg);
    size_t next_msgSize=strlen(new_msg);
    size_t new_size=msgSize+next_msgSize+2;
    string temp_str=malloc(new_size*sizeof(char));
#   endif

    // 黏贴
#   ifndef STRING_H
    strcat(temp_str,self->msg);
    if(msgSize!=0&&next_msgSize!=0) strcat(temp_str,'\n');
    strcat(temp_str,new_msg);
#   endif
    return new_exception(res,temp_str);
}

status exception_get(exception self){
    return self->status;
}

Exception exception_down(exception self,status new_status){
    if(self==NULL){
        return new_exception(ERROR,"exception_add: 传入self指针为空!");
    };
    status_down(&self->status,new_status);
    return new_exception(self->status,self->msg);
}

status free_exception(exception self){
    status res=SUCCESS;
    if(self==NULL) status_down(&res,WARRING);
    status_down(&res,nfree(self->msg));
    status_down(&res,nfree(self));
    return res;
}

interface new_interface(size_t itemSize,...){
    interface self=(interface)malloc(sizeof(struct InterFace));
    if(self==NULL) return NULL;
    va_list args;
    va_start(args,itemSize);
    self->_itemSize=itemSize;

    any temp;
    temp=va_arg(args,init_func);
    if(temp==inter_end) goto end;
    self->init=temp;
    temp=va_arg(args,free_func);
    if(temp==inter_end) goto end;
    self->free=temp;
end:
    va_end(args);
    return self;
}

Exception free_interface(interface self){
    status res=SUCCESS;
    if(self==NULL) status_down(&res,WARRING);
    status_down(&res,nfree(self));
    return new_exception(res,"");
}

// 顺序表
// 内部函数

// 检查是否越界
Exception check(sqlist self,int index){
    if(self==NULL) return new_exception(ERROR,"sqlist check: 传入self指针为空!");
    if(index<0||index>self->_size) return new_exception(ERROR,"sqlist check: 越界!");
    return new_exception(SUCCESS,"");
}

// 获取元素大小
size_t get_item_size(sqlist self){
    if(self==NULL) return 0;
    return self->_inter->_itemSize;
}

// 扩容函数
Exception expand(sqlist self){
    if(self==NULL) return new_exception(ERROR,"sqlist expand: 传入self指针为空!");
    size_t newSize=self->_capacity*2;
    self->_data=realloc(self->_data,newSize*get_item_size(self));
    if(self->_data==NULL) return new_exception(ERROR,"sqlist expand: 扩容失败!");
    self->_capacity=newSize;
    return new_exception(SUCCESS,"");
}

// 收缩函数
Exception shrink(sqlist self){
    if(self==NULL) return new_exception(ERROR,"sqlist expand: 传入self指针为空!");
    size_t newSize=self->_capacity/2;
    self->_data=realloc(self->_data,newSize*get_item_size(self));
    if(self->_data==NULL) return new_exception(ERROR,"sqlist expand: 收缩失败!");
    self->_capacity=newSize;
    return new_exception(SUCCESS,"");
}

// 公开函数

sqlist new_sqlist(interface inter){
    if(inter==NULL) return NULL;
    sqlist res=malloc(sizeof(SqList));

    return res;
}

sqlist sqlist_init(sqlist self,interface inter){
    if(self==NULL) return NULL;
    self->_inter=inter;
    self->_size=0;
    self->_capacity=SQLIST_INIT_SIZE;
    self->_data=malloc(self->_capacity*inter->_itemSize);
    for(size_t i=0; i<self->_capacity; i++){
        inter->init(self->_data+i*get_item_size(self),inter->subinter);
    }
}