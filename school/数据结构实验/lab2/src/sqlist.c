#include "sqlist.h"
#include "tools.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// 顺序表
// 内部函数

// 检查是否越界
// Exception check(sqlist self,int index){
//     if(self==NULL) return new_exception(ERROR,"sqlist check: 传入self指针为空!");
//     if(index<0||index>self->_size) return new_exception(ERROR,"sqlist check: 越界!");
//     return new_exception(SUCCESS,"");
// }

// 扩容函数
Exception expand(sqlist self){
    if(self==NULL) return new_exception(ERROR,"sqlist expand: 传入self指针为空!");
    size_t newSize=self->_capacity*2;
    self->_data=realloc(self->_data,newSize*sqlist_get_itemsize(self));
    if(self->_data==NULL) return new_exception(ERROR,"sqlist expand: 扩容失败!");
    self->_capacity=newSize;
    return new_exception(SUCCESS,"");
}

// 收缩函数
Exception shrink(sqlist self){
    if(self==NULL) return new_exception(ERROR,"sqlist expand: 传入self指针为空!");
    size_t newSize=self->_capacity/2;
    self->_data=realloc(self->_data,newSize*sqlist_get_itemsize(self));
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

Exception sqlist_init(sqlist self,interface inter){
    empty_ptr_error("sqlist_init: 传入self指针为空!");
    self->_inter=inter;
    self->_size=0;
    // 初始容量大小
    self->_capacity=SQLIST_INIT_SIZE;
    self->_data=malloc(self->_capacity*inter->_itemSize);
    if(self->_data==NULL) return new_exception(ERROR,"sqlist init: 内存分配失败!");
    sqlist_pointer(self) pItem=self->_data;
    for(size_t i=0; i<self->_capacity; i++){
        if(inter->init) inter->init(self->_data+i,inter->_subinter);
    }
    return new_exception(SUCCESS,"");
}

Exception sqlist_resize(sqlist self,size_t newSize){
    if(newSize>=self->_size){
        self->_data=realloc(self->_data,newSize);
        if(self->_data==NULL) return new_exception(ERROR,"sqlist resize: 扩容失败!");
    }
    else{
        sqlist_pointer(self) pItem=self->_data;
        for(size_t i=newSize; i<self->_size; i++){
            any curItem=pItem+i;
            if(self->_inter->clear) self->_inter->clear(curItem);
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

size_t sqlist_get_itemsize(sqlist self){
    return inter_item_size(self->_inter);
}

any sqlist_at(sqlist self,int index){
    if(index>(int)self->_size||index<0){
        perror("sqlist_at: 下标越界!");
    }
    return (sqlist_pointer(self))self->_data+index;
}

bool sqlist_empty(sqlist self){
    if(self==NULL) return true;
    return self->_size==0;
}

Exception sqlist_clear(sqlist self){
    empty_ptr_error("sqlist_clear: 传入self指针为空!");
    // if(self==NULL) return new_exception(ERROR,"sqlist_clear: 传入self指针为空!");
    self->_size=0;
    sqlist_pointer(self) pItem=self->_data;
    // 清空数据
    for(size_t i=0; i<self->_size; i++){
        any curItem=pItem+i;
        if(self->_inter->clear) self->_inter->clear(curItem);
    }
    // 收缩
    return new_exception(SUCCESS,"");
}

Exception sqlist_push_back(sqlist self,any item){
    Exception e=new_exception(SUCCESS,"");
    self->_size++;
    sqlist_pointer(self) pItem=self->_data;
    if(self->_size>self->_capacity){
        e=expand(self);
    }
    // any newItem=(byte)self->_data+(self->_size-1)*sqlist_get_itemsize(self);
    any newItem=pItem+self->_size-1;
    // interface tinter=self->_inter;
    // #   ifdef CAP_INTER_ERROR
    //     exception temp_e=tinter->init(newItem,tinter->_subinter);
    //     exception_catch(&e,*temp_e);
    //     free_exception(temp_e);
    // #   endif
    // 拷贝构造
    if(self->_inter->copy){
        self->_inter->copy(newItem,item);
    }
    else{
        memcpy(newItem,item,sqlist_get_itemsize(self));
    }
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

any sqlist_c_data(sqlist self){
    return self->_data;
}

Exception free_sqlist(sqlist self){
    empty_ptr_error("free_sqlist: 传入self指针为空!");
    Exception e=sqlist_clear(self);
    exception_down(&e,nfree((any *)&self));
    return e;
}

// 迭代器
sqlist_iterator new_sqlist_iterator(sqlist self,int index){
    if(self==NULL) return NULL;
    sqlist_iterator res=malloc(sizeof(SqList_Iterator));
    sqlist_pointer(self) curItem=self->_data+index;
    res->_list=self;
    res->_index=index;
    res->_curItem=curItem;
    res->back=sqlist_iterator_back;
    res->next=sqlist_iterator_next;
    return res;
}

sqlist_iterator sqlist_iterator_back(sqlist_iterator self){
    if(self==NULL) return NULL;
    // if(self->_index==0) return NULL;
    if(self->_index>0) self->_index--;
    self->_curItem=(sqlist_pointer(self->_list))self->_list->_data+self->_index;
    return self;
}

sqlist_iterator sqlist_iterator_next(sqlist_iterator self){
    if(self==NULL) return NULL;
    self->_index=min(self->_list->_size,self->_index+1);
    self->_curItem=(sqlist_pointer(self->_list))self->_list->_data+self->_index;
    return self;
}

any sqlist_iterator_visit(sqlist_iterator self){
    if(self==NULL) return NULL;
    return self->_curItem;
}

Exception free_sqlist_iterator(sqlist_iterator self){
    return new_exception(nfree((any *)&self),"");
}