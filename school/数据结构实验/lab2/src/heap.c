#include "heap.h"
#include "tools.h"
#include <stdlib.h>
// #include <math.h>

// 内部函数
// 获取父节点下标
size_t father(size_t index){
    return (index-1)/2;
}
// 获取左节点下标
size_t left(size_t index){
    return 2*index+1;
}
// 获取右节点下标
size_t right(size_t index){
    return 2*index+2;
}
// 获取元素大小
static size_t itemsize(heap self){
    sqlist_get_itemsize(self->_heap);
}
// 比较元素大小
bool heap_cmp(heap self,size_t ia,size_t ib){
    return self->cmp(sqlist_at(self->_heap,ia),sqlist_at(self->_heap,ib));
}
// 交换两元素
void heap_swap(heap self,size_t ia,size_t ib){
    swap(itemsize(self),sqlist_at(self->_heap,ia),sqlist_at(self->_heap,ib));
}
// 向上调整
void heap_up(heap self,size_t index){
    while(index>0&&heap_cmp(self,index,father(index))){
        heap_swap(itemsize(self),index,father(index));
        index=father(index);
    }
}
// 向下调整
Exception heap_down(heap self,size_t index){
    while(left(index)>=0){
        size_t now=left(index);
        if(now+1<=heap_size(self)&&heap_cmp(self,now,now+1)) now++;
        if(!heap_cmp(self,now,index)) break;
        heap_swap(self,index,now);
        index=now;
    }
}

// 外部函数
heap new_heap(interface inter,cmp_func cmp){
    if(inter==NULL) return NULL;
    if(cmp==NULL) return NULL;
    heap res=malloc(sizeof(Heap));
    if(res==NULL) return NULL;
    res->cmp=cmp;
    res->_heap=new_sqlist(inter);
    res->_size=&res->_heap->_size;
    if(res->_heap==NULL){
        free(res);
        return NULL;
    }
    return res;
}

heap new_heap_from(sqlist list,cmp_func cmp){
    if(list==NULL) return NULL;
    if(cmp==NULL) return NULL;
    heap res=malloc(sizeof(Heap));
    if(res==NULL) return NULL;
    res->cmp=cmp;
    res->_heap=list;
    res->_size=&list->_size;
    // 重新调整堆
    for(size_t i=(*res->_size-1)/2;i>0;i--){
        heap_down(res,i);
    }
    return res;
}

any heap_top(heap self){
    if(self==NULL) return NULL;
    if(heap_empty(self)) return NULL;
    return sqlist_at(self->_heap,0);
}
size_t heap_size(heap self){
    return *self->_size;
}
bool heap_empty(heap self){
    if(self==NULL) return true;
    return *self->_size==0;
}
Exception heap_pop(heap self){
    if(self==NULL) return new_exception(ERROR,"heap_pop: 传入self指针为空!");
    if(heap_empty(self)) return new_exception(ERROR,"heap_pop: 空堆!");
    Exception e=new_exception(SUCCESS,"");
    // 交换第一个元素和最后一个元素
    heap_swap(self,0,*self->_size-1);
    // 删除最后一个元素
    sqlist_pop_back(self->_heap);
    // 调整堆
    heap_down(self,0);
    return e;
}
Exception heap_push(heap self,any item){
    if(self==NULL) return new_exception(ERROR,"heap_push: 传入self指针为空!");
    if(item==NULL) return new_exception(ERROR,"heap_push: 传入item指针为空!");
    Exception e=new_exception(SUCCESS,"");
    // 添加元素
    sqlist_push_back(self->_heap,item);
    // 调整堆
    heap_up(self,heap_size(self)-1);
    return e;
}
Exception heap_clear(heap self){
    if(self==NULL) return new_exception(ERROR,"heap_clear: 传入self指针为空!");
    if(self->_heap==NULL) return new_exception(ERROR,"heap_clear: 传入sqlist指针为空!");
    Exception e=new_exception(SUCCESS,"");
    // 清空堆
    sqlist_clear(self->_heap);
    // 释放堆
    free_sqlist(self->_heap);
    return e;
}
Exception free_heap(heap self){
    if(self==NULL) return new_exception(ERROR,"free_heap: 传入self指针为空!");
    Exception e=new_exception(SUCCESS,"");
    // 释放堆
    heap_clear(self);
    // 释放堆指针
    status res=nfree((any *)&self);
    // 异常降级
    exception_down(&e,res);
    return e;
}