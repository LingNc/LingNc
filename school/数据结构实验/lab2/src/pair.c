#include "pair.h"
#include "tools.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// pairinter
pairinter new_pairinter(interface first, interface second){
    if (first == NULL || second == NULL) return NULL;
    pairinter res = malloc(sizeof(PairInter));
    if (res == NULL) return NULL;
    res->first = first;
    res->second = second;
    return res;
}
any pairinter_init(pairinter self, interface inter){
    if (self == NULL) return NULL;
    self->first = NULL;
    self->second = NULL;
    return self;
}
any pairinter_clear(pairinter self){
    if (self == NULL) return NULL;
    self->first = NULL;
    self->second = NULL;
    return self;
}
any free_pairinter(pairinter self){
    if (self == NULL) return NULL;
    free_interface(self->first);
    free_interface(self->second);
    // 释放结构体
    sfree(&self);
    return NULL;
}
// interface pairinter_create_inter(){
//     return new_interface(sizeof(PairInter), NULL, pairinter_init, NULL, pairinter_clear, NULL);
// }

// pair
pair new_pair(any first, any second, pairinter pinter){
    pair res = malloc(sizeof(Pair));
    if (res == NULL) return NULL;
    // 初始化
    res->first = malloc(pinter->first->_itemSize);
    res->second = malloc(pinter->second->_itemSize);
    if (res->first == NULL || res->second == NULL){
        sfree(&res);
        return NULL;
    }
    res->_pinter = pinter;
    // 拷贝构造
    if (pinter->first->copy){
        pinter->first->copy(res->first, first);
    }
    else{
        memcpy(res->first, first, pinter->first->_itemSize);
    }
    if (pinter->second->copy){
        pinter->second->copy(res->second, second);
    }
    else{
        memcpy(res->second, second, pinter->second->_itemSize);
    }
    return res;
} // new_pair

// any pair_init(pair self, interface inter){
//     if (self == NULL || inter == NULL) return NULL;
//     self->_pinter = inter;
//     pairinter pinter = inter;
//     self->first = malloc(pinter->first->_itemSize);
//     self->second = malloc(pinter->second->_itemSize);
//     if (self->first == NULL || self->second == NULL){
//         sfree(&self);
//         return NULL;
//     }
//     return self;
// } // pair_init

any pair_copy(pair self, pair other){
    if (other == NULL) return NULL;
    // 如果self为空就重分配self内存
    if(self==NULL){
        self=new_pair(NULL,NULL,other->_pinter);
        if(self==NULL){
            return NULL;
        }
    }
    pairinter pinter = other->_pinter;
    if(self->_pinter==NULL) self->_pinter=pinter;
    // 重新分配内存
    // sfree(&self->first);
    // sfree(&self->second);
    // 如果有copy构造说明是手动管理的内存，
    // 如果没有说明是由系统管理的是声明的静态变量，大概率是临时变量需要被赋值到新的位置
    // 如果是静态变量，请复制的时候保证两边数据大小一样，不然会报错
    // 如果复制到NULL请注意很可能会出现问题
    bool is_static=(self->_pinter->first->copy==NULL)?true:false;
    // first
    if(is_static){
        if(self->first == NULL){
            self->first = malloc(pinter->first->_itemSize);
        }
        if(self->_pinter->first->_itemSize!=other->_pinter->first->_itemSize){
            char msg[256];
            snprintf(msg, sizeof(msg), "pair_copy: 目标 pair first 是静态的，尝试将%zu大小的变量复制到%zu大小的静态变量上",
                     other->_pinter->first->_itemSize, self->_pinter->first->_itemSize);
            perror(msg);
            return NULL;
        }
        memcpy(self->first, other->first, pinter->first->_itemSize);
    }
    else{
        self->first = realloc(self->first,other->_pinter->first->_itemSize);
        if(pinter->first->copy) pinter->first->copy(self->first, other->first);
        else memcpy(self->first, other->first, pinter->first->_itemSize);
    }
    // second
    if(is_static){
        if(self->second == NULL){
            self->second = malloc(pinter->second->_itemSize);
        }
        if(self->_pinter->second->_itemSize!=other->_pinter->second->_itemSize){
            char msg[256];
            snprintf(msg, sizeof(msg), "pair_copy: 目标 pair second 是静态的，尝试将%zu大小的变量复制到%zu大小的静态变量上",
                     other->_pinter->second->_itemSize, self->_pinter->second->_itemSize);
            perror(msg);
            return NULL;
        }
        memcpy(self->second, other->second, pinter->second->_itemSize);
    }
    else{
        self->second = realloc(self->second,other->_pinter->second->_itemSize);
        if(pinter->second->copy) pinter->second->copy(self->second, other->second);
        else memcpy(self->second, other->second, pinter->second->_itemSize);
    }
    if (self->first == NULL || self->second == NULL){
        sfree(&self);
        return NULL;
    }
    self->_pinter = pinter;
    return self;
} // pair_copy

any pair_clear(pair self){
    if (self == NULL) return NULL;
    sfree(&self->first);
    sfree(&self->second);
    return self;
}

void pair_print(pair self){
    if (self == NULL) return;
    printf("piar( ");
    if (self->_pinter->first->print){
        self->_pinter->first->print(self->first);
    }
    else{
        printf("%p ,", self->first);
    }
    if (self->_pinter->second->print){
        self->_pinter->second->print(self->second);
    }
    else{
        printf(" %p", self->second);
    }
    printf(" )\n");
}

any free_pair(pair self){
    if (self == NULL) return NULL;
    pair_clear(self);
    sfree(&self);
    return NULL;
}

interface pair_create_inter(){
    // 码表 i:init c:copy l:clear m:cmp f:free
    return new_interface(sizeof(Pair), NULL, "clp", pair_copy, pair_clear, pair_print);
}
