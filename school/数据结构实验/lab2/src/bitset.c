#include "bitset.h"
#include "exception.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 从size转所需字节大小函数
inline static size_t stoc(size_t size){
    return (size%8)?(size/8+1):(size/8);
}

// 从cap转为字节数量
inline static size_t ctos(size_t cap){
    return cap*8;
}


// 扩容函数
static Exception expand(bitset self,size_t maxSize){
    if(self==NULL) return new_exception(ERROR,"bitset expand: 传入self指针为空!");
    size_t newCap=stoc(maxSize);
    self->_data=realloc(self->_data,newCap);
    if(self->_data==NULL) return new_exception(ERROR,"bitset expand: 扩容失败!");
    self->_size=maxSize;
    self->_capacity=newCap;
    return new_exception(SUCCESS,"");
}

bitset new_bitset(size_t size){
    bitset res = malloc(sizeof(Bitset));
    if(res==NULL) return NULL;
    res->_size=size;
    bitset_init(res,NULL);
    return res;
} // new_bitset

bitset bitset_init(bitset self,interface inter){
    if(self==NULL) return NULL;
    // 计算容量
    self->_capacity=stoc(self->_size);
    self->_data=calloc(self->_capacity,sizeof(Byte));
    if(self->_data==NULL) return NULL;
    return self;
} // bitset_init

any bitset_copy(bitset self,bitset other){
    if(other==NULL) return NULL;
    // 计算容量
    size_t maxSize=other->_size;
    // 存在则扩容，不存在初始化
    if(self) expand(self,maxSize);
    else self=new_bitset(maxSize);
    // 拷贝
    memcpy(self->_data,other->_data,self->_capacity);
    return self;
} // bitset_copy

bool bitset_get(bitset self,size_t index){
    if(self==NULL){
        Exception e=new_exception(ERROR,"bitset_at: 传入 self 指针为空!");
        perror(e.msg);
        return false;
    }
    if(index>self->_size) return false;
    else return ((self->_data[index/8]>>index%8)&1);
}

any bitset_set(bitset self,size_t index,bool value){
    if(self==NULL){
        Exception e=new_exception(ERROR,"bitset_set: 传入 self 指针为空!");
        perror(e.msg);
        return NULL;
    }
    // 如果超出最大长度报错
    if(index>BITSET_MAX_SIZE){
        char msg[1000];
        sprintf(msg,"bitset_get: 超出最大长度! %zu > %u",index,BITSET_MAX_SIZE);
        Exception e=new_exception(ERROR,msg);
        perror(e.msg);
        return NULL;
    }
    // 超过容量分配新的
    if(index>ctos(self->_capacity)){
        expand(self,index);
        self->_capacity=stoc(index);
    }
    self->_size=index;
    // 设置为1
    if(value) self->_data[index/8]|=(1<<index%8);
    // 设置为0
    else self->_data[index/8]&=~(1<<index%8);
    return self;
} // bitset_set

any bitset_clear(bitset self){
    if(self==NULL) return NULL;
    memset(self->_data,0,self->_capacity);
    return self;
} // bitset_clear

void bitset_print(bitset self){
    if(self==NULL) return;
    printf("Bitset: ");
    // 打印字节
    for(size_t i=0;i<self->_size;i++){
        if(i!=0&&i%8==0) putchar(' ');
        // 打印每一位
        printf("%d",((self->_data[i/8]>>i%8)&1));
    }
    putchar('\n');
} // bitset_print

any free_bitset(bitset self){
    if(self==NULL) return NULL;
    sfree(&self->_data);
    sfree(&self);
    return NULL;
} // free_bitset

interface bitset_create_inter(){
    return new_interface(sizeof(Bitset),NULL,"iclpf",bitset_init,bitset_copy,bitset_clear,bitset_copy,free_bitset);
}