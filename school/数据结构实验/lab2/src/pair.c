#include "pair.h"
#include "tools.h"
#include <string.h>
#include <stdlib.h>

// pair_inter
pair_inter new_pair_inter(interface first,interface second){
    if(first==NULL||second==NULL) return NULL;
    pair_inter res=malloc(sizeof(Pair_inter));
    if(res==NULL) return NULL;
    res->first=first;
    res->second=second;
    return res;
}
any pair_inter_init(pair_inter self,interface inter){
    if(self==NULL) return NULL;
    self->first=NULL;
    self->second=NULL;
    return self;
}
any pair_inter_clear(pair_inter self){
    if(self==NULL) return NULL;
    self->first=NULL;
    self->second=NULL;
    return self;
}
any free_pair_inter(pair_inter self){
    if(self==NULL) return NULL;
    free_interface(self->first);
    free_interface(self->second);
    // 释放结构体
    nfree((any *)&self);
    return NULL;
}

// pair
pair new_pair(any first,any second,any inter){
    pair res=malloc(sizeof(Pair));
    if(res==NULL) return NULL;
    pair_init(res,inter);
    pair_inter pinter=inter;
    // 拷贝构造
    if(pinter->first->copy){
        pinter->first->copy(res->first,first);
    }
    else{
        memcpy(res->first,first,pinter->first->_itemSize);
    }
    if(pinter->second->copy){
        pinter->second->copy(res->second,second);
    }
    else{
        memcpy(res->second,second,pinter->second->_itemSize);
    }
    return res;
} // new_pair

any pair_init(pair self,any inter){
    if(self==NULL||inter==NULL) return NULL;
    self->_inter=inter;
    pair_inter pinter=inter;
    self->first=malloc(pinter->first->_itemSize);
    self->second=malloc(pinter->second->_itemSize);
    if(self->first==NULL||self->second==NULL){
        nfree((any *)&self);
        return NULL;
    }
    return self;
} // pair_init

any pair_copy(pair self,pair other){
    if(self==NULL||other==NULL) return NULL;
    // 判断结构大小是否相同
    if(self->_inter->first->_itemSize==other->_inter->first->_itemSize&&
        self->_inter->second->_itemSize==other->_inter->second->_itemSize){
        // 这里不需要重新分配内存
        pair_inter pinter=other->_inter;
        self->_inter=pinter;
        // 拷贝构造
        if(pinter->first->copy){
            pinter->first->copy(self->first,other->first);
        }
        else{
            memcpy(self->first,other->first,pinter->first->_itemSize);
        }
        if(pinter->second->copy){
            pinter->second->copy(self->second,other->second);
        }
        else{
            memcpy(self->second,other->second,pinter->second->_itemSize);
        }
    }
    else{
        // 这里需要重新分配内存
        nfree((any *)&self->first);
        nfree((any *)&self->second);
        self->first=malloc(other->_inter->first->_itemSize);
        self->second=malloc(other->_inter->second->_itemSize);
        if(self->first==NULL||self->second==NULL){
            nfree((any *)&self);
            return NULL;
        }
        pair_copy(self,other);
    }
    return self;
} // pair_copy

any pair_clear(pair self){
    if(self==NULL) return NULL;
    nfree((any *)&self->first);
    nfree((any *)&self->second);
    return self;
}

any free_pair(pair self){
    if(self==NULL) return NULL;
    pair_clear(self);
    nfree((any *)&self);
    return NULL;
}

interface pair_create_inter(){
    return new_interface(sizeof(Pair),NULL,pair_init,pair_copy,pair_clear,NULL);
}