#include "pair.h"
#include "tools.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// pair
pair new_pair(any first, any second, interfaces inters){
    pair res = malloc(sizeof(Pair));
    if (res == NULL) return NULL;
    // 初始化
    pair_init(res, inters);
    res->first = malloc(inters_size(inters, 0));
    res->second = malloc(inters_size(inters, 1));
    if (res->first == NULL || res->second == NULL){
        sfree(&res);
        return NULL;
    }
    res->_inters=inters;
    // 拷贝构造
    if (inters_inter(inters,0)->copy){
        inters_inter(inters,0)->copy(res->first, first);
    }
    else{
        memcpy(res->first, first, inters_inter(inters,0)->_itemSize);
    }
    if (inters_inter(inters,1)->copy){
        inters_inter(inters,1)->copy(res->second, second);
    }
    else{
        memcpy(res->second, second, inters_size(inters,1));
    }
    return res;
} // new_pair

any pair_init(pair self, interfaces inters){
    if (self == NULL) return NULL;
    self->_inters=inters;
    self->first=NULL;
    self->second=NULL;
    return self;
} // pair_init

any pair_copy(pair self, pair other){
    if (other == NULL) return NULL;
    // 如果self为空就重分配self内存
    if(self==NULL){
        self=new_pair(NULL,NULL,other->_inters);
        if(self==NULL){
            return NULL;
        }
    }
    interfaces inters = other->_inters;
    if(self->_inters==NULL) self->_inters=inters;
    // 重新分配内存
    self->first=realloc(self->first,inters_size(inters, 0));
    self->second=realloc(self->second,inters_size(inters, 1));
    // 判断是否是静态变量
    // first
    if(inters_inter(inters, 0)->copy)
        inters_inter(inters, 0)->copy(self->first, other->first);
    else
        memcpy(self->first, other->first, inters_size(inters, 0));
    // second
    if(inters_inter(inters, 1)->copy)
        inters_inter(inters, 1)->copy(self->second, other->second);
    else
        memcpy(self->second, other->second, inters_size(inters, 1));
    // 复制接口
    self->_inters=inters;
    return self;
} // pair_copy

any pair_move(pair dest, pair src){
    if(src==NULL) return NULL;
    if(dest==NULL){
        dest=new_pair(NULL,NULL,src->_inters);
        if(dest==NULL) return NULL;
    }
    smove(&dest->first,&src->first,8);
    smove(&dest->second,&src->second,8);
    return dest;
} // pair_move

any pair_clear(pair self){
    if (self == NULL) return NULL;
    if(self->_inters==NULL) return self;
    // 清除数据
    if(inters_inter(self->_inters, 0)->clear)
        inters_inter(self->_inters, 0)->clear(self->first);
    else
        sfree(&self->first);
    if(inters_inter(self->_inters,1)->clear)
        inters_inter(self->_inters,1)->clear(self->second);
    else
        sfree(&self->second);
    return self;
}

void pair_print(pair self){
    if (self == NULL) return;
    printf("piar( ");
    if (inters_inter(self->_inters, 0)->print){
        inters_inter(self->_inters, 0)->print(self->first);
    }
    else{
        printf("%p, ", self->first);
    }
    printf(" ");
    if (inters_inter(self->_inters, 1)->print){
        inters_inter(self->_inters, 1)->print(self->second);
    }
    else{
        printf("%p", self->second);
    }
    printf(" )\n");
}

any free_pair(pair self){
    if (self == NULL) return NULL;
    pair_clear(self);
    sfree(&self);
    return NULL;
}

interfaces pair_create_inters(){
    // 码表 i:init c:copy l:clear m:cmp f:free
    return new_interfaces(
        NULL,
        1,
        new_interface(sizeof(Pair),NULL,"iclp",pair_init,pair_copy,pair_clear,pair_print)
        );
}
