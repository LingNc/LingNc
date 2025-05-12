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
    if (self == NULL) return new_exception(ERROR, "sqlist expand: 传入self指针为空!");
    size_t newSize = self->_capacity * 2;
    self->_data = realloc(self->_data, newSize * sqlist_get_itemsize(self));
    if (self->_data == NULL) return new_exception(ERROR, "sqlist expand: 扩容失败!");
    self->_capacity = newSize;
    return new_exception(SUCCESS, "");
}

// 收缩函数
Exception shrink(sqlist self){
    if (self == NULL) return new_exception(ERROR, "sqlist expand: 传入self指针为空!");
    size_t newSize = self->_capacity / 2;
    self->_data = realloc(self->_data, newSize * sqlist_get_itemsize(self));
    if (self->_data == NULL) return new_exception(ERROR, "sqlist expand: 收缩失败!");
    self->_capacity = newSize;
    return new_exception(SUCCESS, "");
}

// 空指针错误函数
#define empty_ptr_error(msg) if(self==NULL) return new_exception(ERROR,msg)

// 公开函数

sqlist new_sqlist(interface inter){
    if (inter == NULL) return NULL;
    sqlist res = calloc(1,sizeof(SqList));
    sqlist_init(res, inter);
    return res;
}

Exception sqlist_init(sqlist self, interface inter){
    empty_ptr_error("sqlist_init: 传入self指针为空!");
    self->_inter = inter;
    self->_size = 0;
    // 初始容量大小
    self->_capacity = SQLIST_INIT_SIZE;
    self->_data = calloc(self->_capacity, inter->_itemSize);
    if (self->_data == NULL) return new_exception(ERROR, "sqlist init: 内存分配失败!");
    sqlist_pointer(self) pdata = self->_data;
    for (size_t i = 0; i < self->_capacity; i++){
        if (inter->init) inter->init( pdata[i], inter->_subinter);
    }
    return new_exception(SUCCESS, "");
}

Exception sqlist_resize(sqlist self, size_t newSize){
    if (newSize >= self->_size){
        self->_data = realloc(self->_data, newSize);
        if (self->_data == NULL) return new_exception(ERROR, "sqlist resize: 扩容失败!");
    }
    else{
        sqlist_pointer(self) pItem = self->_data;
        for (size_t i = newSize; i < self->_size; i++){
            any curItem = pItem[i];
            if (self->_inter->clear) self->_inter->clear(curItem);
        }
        self->_data = realloc(self->_data, newSize);
        if (self->_data == NULL) return new_exception(ERROR, "sqlist resize: 收缩失败!");
    }
    self->_capacity = newSize;
    return new_exception(SUCCESS, "");
}

size_t sqlist_size(sqlist self){
    if (self == NULL) return 0;
    return self->_size;
}

size_t sqlist_get_itemsize(sqlist self){
    return inter_size(self->_inter);
}

any sqlist_at(sqlist self, int index){
    if (index > (int)self->_size || index < 0){
        perror("sqlist_at: 下标越界!");
    }
    return ((sqlist_pointer(self))self->_data)[index];
}

any sqlist_modify(sqlist self,int index, any newItem){
    if (self == NULL) return NULL;
    sqlist_pointer(self) pitem=self->_data;
    any item=pitem[index];
    if (self->_inter->copy){
        self->_inter->copy(item, newItem);
    }
    else{
        memcpy(item, newItem, sqlist_get_itemsize(self));
    }
    return item;
}

bool sqlist_empty(sqlist self){
    if (self == NULL) return true;
    return self->_size == 0;
}

Exception sqlist_clear(sqlist self){
    empty_ptr_error("sqlist_clear: 传入self指针为空!");
    // if(self==NULL) return new_exception(ERROR,"sqlist_clear: 传入self指针为空!");
    self->_size = 0;
    sqlist_pointer(self) pdata = self->_data;
    // 清空数据
    for (size_t i = 0; i < self->_size; i++){
        any curItem = pdata[i];
        if (self->_inter->clear) self->_inter->clear(curItem);
    }
    // 收缩
    return new_exception(SUCCESS, "");
}

Exception sqlist_push_back(sqlist self, any item){
    Exception e = new_exception(SUCCESS, "");
    self->_size++;
    if (self->_size > self->_capacity){
        e = expand(self);
    }
    sqlist_pointer(self) pdata = self->_data;
    // any newItem=(byte)self->_data+(self->_size-1)*sqlist_get_itemsize(self);
    any newItem = pdata[self->_size - 1];
    // #   ifdef CAP_INTER_ERROR
    // #   endif
    // 初始化
    if (self->_inter->init){
        self->_inter->init(newItem, self->_inter->_subinter);
    }
    // 拷贝构造
    if (self->_inter->copy){
        self->_inter->copy(newItem, item);
    }
    else{
        memcpy(newItem, item, sqlist_get_itemsize(self));
    }
    return e;
}

Exception sqlist_pop_back(sqlist self){
    if (self == NULL) return new_exception(ERROR, "sqlist_pop_back: 传入self指针为空!");
    if (self->_size == 0) return new_exception(ERROR, "sqlist_pop_back: 空顺序表!");
    Exception e = new_exception(SUCCESS, "");
    self->_size--;
    if (self->_size < self->_capacity / 4){
        e = shrink(self);
    }
    return e;
}

void sqlist_print(sqlist self){
    if (self == NULL) return;
    printf("顺序表元素:\n");
    if (self->_inter->print){
        for (size_t i = 0; i < self->_size; i++){
            self->_inter->print(sqlist_at(self,i));
            putchar('\n');
        }
    }
    else{
        for (size_t i = 0; i < self->_size; i++){
            printf("%zu: %p\n", i, sqlist_at(self, i));
        }
    }
}

sqlist_iterator sqlist_begin(sqlist self){
    return new_sqlist_iterator(self, 0);
}

sqlist_iterator sqlist_end(sqlist self){
    return new_sqlist_iterator(self, self->_size);
}

any sqlist_c_data(sqlist self){
    return self->_data;
}

// 查找表 check 返回 1满足条件 0不满足,找到第一个满足条件的
any sqlist_bsearchf(sqlist self, any key, bool (*check)(any, any)){
    return bsearchf(key, self->_data, self->_size, sqlist_get_itemsize(self), check);
}

any sqlist_sort(sqlist self, int (*cmp)(c_any,c_any)){
    if (self == NULL) return NULL;
    size_t size = self->_size;
    qsort(self->_data, size, sqlist_get_itemsize(self), cmp);
    return self;
}

Exception free_sqlist(sqlist self){
    empty_ptr_error("free_sqlist: 传入self指针为空!");
    Exception e = sqlist_clear(self);
    exception_down(&e, sfree(&self));
    return e;
}

// 迭代器
sqlist_iterator new_sqlist_iterator(sqlist self, int index){
    if (self == NULL) return NULL;
    sqlist_iterator res = malloc(sizeof(SqList_Iterator));
    sqlist_pointer(self) pdata = self->_data ;
    res->_list = self;
    res->_index = index;
    res->_curItem = pdata[index];
    res->back = sqlist_iterator_back;
    res->next = sqlist_iterator_next;
    return res;
}

sqlist_iterator sqlist_iterator_back(sqlist_iterator self){
    if (self == NULL) return NULL;
    // if(self->_index==0) return NULL;
    if (self->_index > 0) self->_index--;
    self->_curItem = (sqlist_pointer(self->_list))self->_list->_data + self->_index;
    return self;
}

sqlist_iterator sqlist_iterator_next(sqlist_iterator self){
    if (self == NULL) return NULL;
    self->_index = min(self->_list->_size, self->_index + 1);
    self->_curItem = (sqlist_pointer(self->_list))self->_list->_data + self->_index;
    return self;
}

any sqlist_iterator_visit(sqlist_iterator self){
    if (self == NULL) return NULL;
    return self->_curItem;
}

Exception free_sqlist_iterator(sqlist_iterator self){
    return new_exception(sfree(&self), "");
}