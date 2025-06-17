#include "heap.h"
#include "tools.h"
#include <stdlib.h>
// #include <math.h>

// 内部函数
// 获取父节点下标
#define father(index) ((index-1)/2)
// size_t father(size_t index){
//     return (index-1)/2;
// }
// 获取左节点下标
#define left(index) (2*index+1)
// size_t left(size_t index){
//     return 2*index+1;
// }
// 获取右节点下标
#define right(index) (2*index+2)
// size_t right(size_t index){
//     return 2*index+2;
// }
// 获取元素大小
#define heap_itemsize(self) sqlist_itemsize(self->_heap)
// static size_t itemsize(heap self){
//     return sqlist_get_itemsize(self->_heap);
// }
// 比较元素大小
bool heap_cmp(heap self,size_t ia,size_t ib){
    return self->cmp(sqlist_at(self->_heap,ia),sqlist_at(self->_heap,ib));
}
// 交换两元素
void heap_swap(heap self,size_t ia,size_t ib){
    mswap(sqlist_at(self->_heap,ia),sqlist_at(self->_heap,ib),heap_inter(self));
}
// 向上调整
void heap_up(heap self,size_t index){
    while(index>0&&heap_cmp(self,index,father(index))){
        heap_swap(self,index,father(index));
        index=father(index);
    }
}
// 向下调整
void heap_down(heap self,size_t index){
    size_t heapSize=heap_size(self);
    while(left(index)<heapSize){  // 注意：这里改为 < 而不是 <=
        size_t smallerChild=left(index);
        // 如果右子节点存在且比左子节点更符合堆条件
        if(right(index)<heapSize&&heap_cmp(self,right(index),smallerChild)){
            smallerChild=right(index);
        }
        // 如果当前节点已经满足堆条件，退出
        if(!heap_cmp(self,smallerChild,index))
            break;
        // 交换当前节点与符合条件的子节点
        heap_swap(self,index,smallerChild);
        index=smallerChild;
    }
}

// 外部函数
heap new_heap(interfaces inter,cmp_func cmp){
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
    // 从最后一个非叶子节点开始，向下调整到根节点
    if(*res->_size>0){
        // size_t i>=0 时 i--会等于-1造成死循环
        for(size_t i=(*res->_size)/2;i-->0;){
            heap_down(res,i);
        }
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
    // 不在这里释放self->_heap，应该由free_heap函数完成
    // free_sqlist(self->_heap);
    return e;
}
Exception free_heap(heap self){
    if(self==NULL) return new_exception(ERROR,"free_heap: 传入self指针为空!");
    Exception e=new_exception(SUCCESS,"");
    // 释放堆
    heap_clear(self);
    // 释放堆指针
    status res=sfree(&self);
    // 异常降级
    exception_down(&e,res);
    return e;
}