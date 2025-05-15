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
    self->_data = realloc(self->_data, newSize * sqlist_itemsize(self));
    if (self->_data == NULL) return new_exception(ERROR, "sqlist expand: 扩容失败!");
    self->_capacity = newSize;
    return new_exception(SUCCESS, "");
}

// 收缩函数
Exception shrink(sqlist self){
    if (self == NULL) return new_exception(ERROR, "sqlist expand: 传入self指针为空!");
    size_t newSize = self->_capacity / 2;
    self->_data = realloc(self->_data, newSize * sqlist_itemsize(self));
    if (self->_data == NULL) return new_exception(ERROR, "sqlist expand: 收缩失败!");
    self->_capacity = newSize;
    return new_exception(SUCCESS, "");
}

// 空指针错误函数
#define empty_ptr_error(msg) if(self==NULL) return new_exception(ERROR,msg)


// 公开函数

sqlist new_sqlist(interfaces inter){
    if (inter == NULL) return NULL;
    sqlist res = calloc(1,sizeof(SqList));
    sqlist_init(res, inter);
    return res;
}

Exception sqlist_init(sqlist self, interfaces inter){
    empty_ptr_error("sqlist_init: 传入self指针为空!");
    self->_inter = inter;
    self->_size = 0;
    // 初始容量大小
    self->_capacity = SQLIST_INIT_SIZE;
    self->_data = calloc(self->_capacity, inters_dsize(inter));
    if (self->_data == NULL) return new_exception(ERROR, "sqlist init: 内存分配失败!");
    sqlist_pointer(self) pdata = self->_data;
    for (size_t i = 0; i < self->_capacity; i++){
        if(sqlist_inter(self)->init)
        sqlist_inter(self)->init(pdata[i],sqlist_inter(self)->_subInters);
    }
    return new_exception(SUCCESS, "");
}

any sqlist_move(sqlist dest,sqlist src){
    if (src == NULL) return NULL;
    if(dest==NULL){
        dest=new_sqlist(src->_inter);
        if(dest==NULL) return NULL;
    }
    // 移动数据
    smove(&dest->_data,&src->_data,sizeof(src->_data));
    // 移动大小
    smove(&dest->_size,&src->_size,sizeof(src->_size));
    // 移动容量
    smove(&dest->_capacity,&src->_capacity,sizeof(src->_capacity));
    dest->_inter=src->_inter;
    return dest;
}

Exception sqlist_resize(sqlist self,size_t newSize){
    if (newSize >= self->_size){
        self->_data = realloc(self->_data, newSize);
        if (self->_data == NULL) return new_exception(ERROR, "sqlist resize: 扩容失败!");
    }
    else{
        sqlist_pointer(self) pItem = self->_data;
        for (size_t i = newSize; i < self->_size; i++){
            any curItem = pItem[i];
            if(sqlist_inter(self)->clear)
                sqlist_inter(self)->clear(curItem);
        }
        self->_data = realloc(self->_data, newSize);
        if (self->_data == NULL) return new_exception(ERROR, "sqlist resize: 收缩失败!");
    }
    self->_capacity = newSize;
    return new_exception(SUCCESS, "");
}

sqlist sqlist_insert(sqlist self,int index,any item){
    if(self==NULL || item==NULL) return NULL;
    if(index<0||index>cast(int,self->_size)){
        perror("sqlist_insert: 下标越界!");
    }
    // 扩容
    if(self->_size>=self->_capacity){
        expand(self);
    }
    sqlist_pointer(self) pdata=self->_data;
    // 向后移动一个数据
    memmove(pdata+index+1,pdata+index,(self->_size-index)*sqlist_itemsize(self));
    // 插入数据
    any newItem=pdata[index];
    // 移动数据
    if(sqlist_inter(self)->copy||sqlist_inter(self)->move){
        mmove(newItem,item,sqlist_inter(self));
    }
    // 退化为拷贝数据
    else{
        memcpy(newItem,item,sqlist_itemsize(self));
    }
    // 增加大小
    self->_size++;
    return self;
}

sqlist sqlist_insert_c(sqlist self,int index,any item){
    if(self==NULL || item==NULL) return NULL;
    if(index<0||index>cast(int,self->_size)){
        perror("sqlist_insert: 下标越界!");
    }
    // 扩容
    if(self->_size>=self->_capacity){
        expand(self);
    }
    sqlist_pointer(self) pdata=self->_data;
    // 向后移动一个数据
    memmove(pdata+index+1,pdata+index,(self->_size-index)*sqlist_itemsize(self));
    // 插入数据
    any newItem=pdata[index];
    // 拷贝数据
    if(sqlist_inter(self)->copy)
        sqlist_inter(self)->copy(newItem,item);
    else
        memcpy(newItem,item,sqlist_itemsize(self));
    // 增加大小
    self->_size++;
    return self;
}

size_t sqlist_size(sqlist self){
    if (self == NULL) return 0;
    return self->_size;
}

// size_t sqlist_itemsize(sqlist self){
//     return inters_dsize(self->_inter);
// }

any sqlist_at(sqlist self, int index){
    if (index > (int)self->_size || index < 0){
        perror("sqlist_at: 下标越界!");
    }
    return ((sqlist_pointer(self))self->_data)[index];
}

any sqlist_set(sqlist self,int index, any newItem){
    if (self == NULL) return NULL;
    sqlist_pointer(self) pitem=self->_data;
    any item=pitem[index];
    // 移动构造
    if(sqlist_inter(self)->copy||sqlist_inter(self)->move){
        mmove(item,newItem,sqlist_inter(self));
    }
    // 退化为拷贝构造
    else{
        memcpy(item,newItem,sqlist_itemsize(self));
    }
    return item;
}
any sqlist_set_c(sqlist self,int index, any newItem){
    if (self == NULL) return NULL;
    sqlist_pointer(self) pitem=self->_data;
    if(sqlist_inter(self)->copy)
        sqlist_inter(self)->copy(pitem[index],newItem);
    else
        memcpy(pitem[index],newItem,inters_dsize(self->_inter));
    return pitem[index];
}

bool sqlist_empty(sqlist self){
    if (self == NULL) return true;
    return self->_size == 0;
}

Exception sqlist_clear(sqlist self){
    empty_ptr_error("sqlist_clear: 传入self指针为空!");
    sqlist_pointer(self) pdata = self->_data;
    // 清空数据
    for (size_t i = 0; i < self->_size; i++){
        any curItem = pdata[i];
        if(sqlist_inter(self)->clear)
            sqlist_inter(self)->clear(curItem);
        else
            memset(curItem, 0, inters_dsize(self->_inter));
    }
    self->_size = 0;
    return new_exception(SUCCESS, "");
}

Exception sqlist_push_back(sqlist self, any item){
    Exception e = new_exception(SUCCESS, "");
    self->_size++;
    if (self->_size > self->_capacity){
        e = expand(self);
    }
    sqlist_pointer(self) pdata = self->_data;
    // any newItem=(byte)self->_data+(self->_size-1)*sqlist_itemsize(self);
    any newItem = pdata[self->_size - 1];
    // #   ifdef CAP_INTER_ERROR
    // #   endif
    // 初始化
    // if (sqlist_inter(self)->init){
    //     sqlist_inter(self)->init(newItem, sqlist_sinter(self));
    // }
    // 移动添加
    if(sqlist_inter(self)->copy||sqlist_inter(self)->move){
        mmove(newItem, item, sqlist_inter(self));
    }
    // 退化为拷贝添加
    else{
        memcpy(newItem, item, sqlist_itemsize(self));
    }
    return e;
}

// 拷贝传入
Exception sqlist_push_back_c(sqlist self, any item){
    Exception e = new_exception(SUCCESS, "");
    self->_size++;
    if (self->_size > self->_capacity){
        e = expand(self);
    }
    sqlist_pointer(self) pdata = self->_data;
    any newItem = pdata[self->_size - 1];
    if(sqlist_inter(self)->copy){
        sqlist_inter(self)->copy(newItem, item);
    }
    else{
        memcpy(newItem, item, inters_dsize(self->_inter));
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
    if (sqlist_inter(self)->print){
        for (size_t i = 0; i < self->_size; i++){
            sqlist_inter(self)->print(sqlist_at(self,i));
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
    return bsearchf(key, self->_data, self->_size, sqlist_itemsize(self), check);
}

any sqlist_sort(sqlist self, int (*cmp)(c_any,c_any)){
    if (self == NULL) return NULL;
    size_t size = self->_size;
    qsort(self->_data, size, sqlist_itemsize(self), cmp);
    return self;
}

any sqlist_copy(sqlist self,sqlist other){
    if(other==NULL) return NULL;
    // 清除原有数据
    sqlist_clear(self);
    // 设置大小
    self->_size=other->_size;
    // 设置容量
    self->_capacity=other->_capacity;
    // 重分配空间
    self->_data=realloc(self->_data,self->_capacity*inters_dsize(other->_inter));
    if(self->_data==NULL) return NULL;
    // 拷贝数据
    sqlist_pointer(self) spdata=self->_data;
    sqlist_pointer(other) opdata=other->_data;
    for(size_t i=0;i<self->_size;i++){
        // 拷贝
        if(sqlist_inter(other)->copy)
            sqlist_inter(other)->copy(spdata[i],opdata[i]);
        else
            memcpy(spdata[i],opdata[i],inters_dsize(other->_inter));
    }
    // 接口传递
    self->_inter=other->_inter;
    return self;
}

Exception free_sqlist(sqlist self){
    empty_ptr_error("free_sqlist: 传入self指针为空!");
    Exception e = sqlist_clear(self);
    exception_down(&e, sfree(&self));
    return e;
}
interfaces sqlist_create_inter(interfaces subinters){
    return new_interfaces(
        NULL,
        1,
        new_interface(
            sizeof(SqList),
            subinters,
            "icvlf",
            sqlist_init,
            sqlist_copy,
            sqlist_move,
            sqlist_clear,
            free_sqlist
            )
    );
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