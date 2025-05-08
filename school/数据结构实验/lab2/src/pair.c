#include "pair.h"
#include "tools.h"
#include <string.h>
#include <stdlib.h>

pair new_pair(any first,any second){
    pair res=malloc(sizeof(Pair));
    if(res==NULL) return NULL;
    res->first=first;
    res->second=second;
    return res;
} // new_pair

exception pair_init(pair self,interface inter){
    if(self==NULL) return NULL;
    self->first=NULL;
    self->second=NULL;
    return self;
} // pair_init

exception pair_clear(pair self){
    if(self==NULL) return NULL;
    nfree((any *)&self->first);
    nfree((any *)&self->second);
}

exception free_pair(pair self){
    if(self==NULL) return NULL;
    pair_clear(self);
    nfree((any *)&self);
}

interface pair_create_inter(){
    return new_interface(sizeof(Pair),NULL,pair_init,pair_clear,NULL);
}