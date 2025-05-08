#include "sqlist.h"
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#ifndef STRING_H
// 动态字符串拼接函数
string nstrcat(const string _str1,const string _str2){
    if(_str1==NULL) return _str2;
    if(_str2==NULL) return _str1;
    size_t str1_len=strlen(_str1);
    size_t str2_len=strlen(_str2);
    size_t new_size=str1_len+str2_len+1;
    string temp_str=malloc(new_size*sizeof(char));
    if(temp_str==NULL) return NULL;
    // 拼接
    strcpy(temp_str,_str1);
    strcat(temp_str,_str2);
    return temp_str;
}
string strapp(string _dest,const string _str){
    if(_dest==NULL) return _str;
    if(_str==NULL) return _dest;
    size_t dest_len=strlen(_dest);
    size_t str_len=strlen(_str);
    size_t new_size=dest_len+str_len+1;
    string temp_str=realloc(_str,new_size*sizeof(char));
    if(temp_str==NULL) return NULL;
    // 拼接
    strcat(temp_str,_str);
    return temp_str;
}
#endif
// 状态退化函数
status status_down(status *self,status new_status){
    if(new_status<*self) *self=new_status;
    return *self;
}

// 安全释放函数
status nfree(any *_ptr){
    if(*_ptr==NULL) return WARRING;
    free(*_ptr);
    *_ptr=NULL;
    return SUCCESS;
}

// 异常处理

Exception new_exception(status status,string msg){
    Exception self;
    Status t=status;
#   ifndef STRING_H
    string temp_str=nstrcat(to_str(status),' ');
    temp_str=strapp(temp_str,msg);
    // 不能free字面量
    // status_down(&t, nfree(&msg));
#   endif
    self.msg=msg;
    self.status=t;
    return self;
}

Exception exception_pass(exception self,Exception e){
    if(self==NULL){
        return new_exception(ERROR,"exception_add: 传入self指针为空!");
    }
    status res=SUCCESS;
    // 异常降级
    status_down(&res,self->status);
    status_down(&res,e.status);
    // 计算大小
#   ifndef STRING_H
    size_t msgSize=strlen(self->msg);
    size_t next_msgSize=strlen(e.msg);
    size_t new_size=msgSize+next_msgSize+2;
    // 使用calloc保证配置后字符串初始化为0
    string temp_str=calloc(new_size,sizeof(char));
#   endif

    // 黏贴
#   ifndef STRING_H
    strcat(temp_str,self->msg);
    if(msgSize!=0&&next_msgSize!=0) strcat(temp_str,'\n');
    strcat(temp_str,e.msg);
#   endif
    self->status=res;
    self->msg=temp_str;
    return *self;
}

Exception exception_catch(exception self,Exception e){
    if(self==NULL){
        return new_exception(ERROR,"exception_catch: 传入self指针为空!");
    }
    // 异常降级
    status res=SUCCESS;
    status_down(&res,self->status);
    status_down(&res,e.status);
    // 计算大小
#   ifndef STRING_H
    size_t msgSize=strlen(self->msg);
    size_t next_msgSize=strlen(e.msg);
    size_t new_size=msgSize+next_msgSize+2;
    string temp_str=calloc(new_size,sizeof(char));
#   endif
    // 黏贴
#   ifndef STRING_H
    strcat(temp_str,e.msg);
    if(msgSize!=0&&next_msgSize!=0) strcat(temp_str,' --> \n');
    strcat(temp_str,self->msg);
#   endif
    self->status=res;
    self->msg=temp_str;
    return *self;
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
    else status_down(&res,nfree(&self->msg));
    status_down(&res,nfree(&self));
    return res;
}

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
    temp=va_arg(args,clear_func);
    if(temp==inter_end) goto end;
    self->clear=temp;
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
    status_down(&res,nfree(&self));
    Exception e=new_exception(res,"");
    if(self->_subinter!=NULL) exception_pass(&e,free_interface(self->_subinter));
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

// 空指针错误函数
#define empty_ptr_error(msg) if(self==NULL) return new_exception(ERROR,msg)

// 公开函数

sqlist new_sqlist(interface inter){
    if(inter==NULL) return NULL;
    sqlist res=malloc(sizeof(SqList));
    sqlist_init(res,inter);
    return res;
}

sqlist sqlist_init(sqlist self,interface inter){
    if(self==NULL) return NULL;
    self->_inter=inter;
    self->_size=0;
    // 初始容量大小
    self->_capacity=SQLIST_INIT_SIZE;
    self->_data=malloc(self->_capacity*inter->_itemSize);
    for(size_t i=0; i<self->_capacity; i++){
        inter->init((byte)self->_data+i*get_item_size(self),inter->_subinter);
    }
}

Exception sqlist_resize(sqlist self,size_t newSize){
    if(newSize>=self->_size){
        self->_data=realloc(self->_data,newSize);
        if(self->_data==NULL) return new_exception(ERROR,"sqlist resize: 扩容失败!");
    }
    else{
        for(size_t i=newSize; i<self->_size; i++){
            any curItem=(byte)self->_data+i*get_item_size(self);
            self->_inter->clear(curItem);
        }
        self->_data=realloc(self->_data,newSize);
        if(self->_data==NULL) return new_exception(ERROR,"sqlist resize: 收缩失败!");
    }
    self->_capacity=newSize;
    return new_exception(SUCCESS,"");
}

size_t sqlist_size(sqlist self){
    if(self==NULL) return 0;
    return self->_size;
}

any sqlist_at(sqlist self,int index){
    if(index>self->_size||index<0) return NULL;
    return (byte)self->_data+index*get_item_size(self);
}

bool sqlist_empty(sqlist self){
    if(self==NULL) return true;
    return self->_size==0;
}

Exception sqlist_clear(sqlist self){
    empty_ptr_error("sqlist_clear: 传入self指针为空!");
    // if(self==NULL) return new_exception(ERROR,"sqlist_clear: 传入self指针为空!");
    self->_size=0;
    self->_capacity=0;
    // 清空数据
    for(size_t i=0; i<self->_size; i++){
        any curItem=(byte)self->_data+i*get_item_size(self);
        self->_inter->clear(curItem);
    }
    // 收缩
    // 暂时没有
    return new_exception(SUCCESS,"");
}

Exception sqlist_push_back(sqlist self,any item){
    Exception e=new_exception(SUCCESS,"");
    self->_size++;
    if(self->_size>self->_capacity){
        e=expand(self);
    }
    any newItem=(byte)self->_data+(self->_size-1)*get_item_size(self);
    interface tinter=self->_inter;
    // #   ifdef CAP_INTER_ERROR
    //     exception temp_e=tinter->init(newItem,tinter->_subinter);
    //     exception_catch(&e,*temp_e);
    //     free_exception(temp_e);
    // #   endif
    memcpy(newItem,item,get_item_size(self));
    return e;
}

Exception sqlist_pop_back(sqlist self){
    if(self==NULL) return new_exception(ERROR,"sqlist_pop_back: 传入self指针为空!");
    if(self->_size==0) return new_exception(ERROR,"sqlist_pop_back: 空顺序表!");
    Exception e=new_exception(SUCCESS,"");
    self->_size--;
    if(self->_size<self->_capacity/4){
        e=shrink(self);
    }
    return e;
}

sqlist_iterator sqlist_begin(sqlist self){
    return new_sqlist_iterator(self,0);
}

sqlist_iterator sqlist_end(sqlist self){
    return new_sqlist_iterator(self,self->_size);
}

Exception free_sqlist(sqlist self){
    empty_ptr_error("free_sqlist: 传入self指针为空!");
    Exception e=sqlist_clear(self);
    exception_down(&e,nfree(self));
    return e;
}

// 迭代器
sqlist_iterator new_sqlist_iterator(sqlist self,int index){
    if(self==NULL) return NULL;
    sqlist_iterator res=malloc(sizeof(SqList_Iterator));
    res->_list=self;
    res->_index=index;
    res->back=sqlist_iterator_back;
    res->next=sqlist_iterator_next;
    return res;
}

sqlist_iterator sqlist_iterator_back(sqlist_iterator self){
    if(self==NULL) return NULL;
    // if(self->_index==0) return NULL;
    self->_index=max(0,self->_index-1);
    self->_curItem=(byte)self->_list->_data+self->_index*get_item_size(self->_list);
    return self;
}

sqlist_iterator sqlist_iterator_next(sqlist_iterator self){
    if(self==NULL) return NULL;
    self->_index=min(self->_list->_size,self->_index+1);
    self->_curItem=(byte)self->_list->_data+self->_index*get_item_size(self->_list);
    return self;
}

Exception free_sqlist_iterator(sqlist_iterator self){
    return new_exception(nfree(&self),"");
}