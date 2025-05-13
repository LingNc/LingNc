#include "huffcode.h"

huffcode new_huffcode(){
    huffcode res = malloc(sizeof(HuffCode));
    if (res == NULL) return NULL;
    res->_code = 0;
    res->_size = 0;
    return res;
}
huffcode huffcode_init(huffcode self){
    if(self==NULL) return NULL;
    self->_code=0;
    self->_size=0;
    return self;
}

void huffcode_print(huffcode self){
    if (self == NULL) return;
    printf("HuffCode: %X %u\n", self->_code, self->_size);
}
bool huffcode_get(huffcode self,Byte index){
    // 超出索引范围
    if(index>64) return false;
    index=64-self->_size+index;
    return (self->_code>>index)&1;
}
any huffcode_set(huffcode self,Byte index,bool value){
    if(self==NULL||index>64) return NULL;
    index=64-self->_size+index;
    self->_code=(self->_code&~(1<<index))|(value<<index);
    return self;
}
void huffcode_inc(huffcode self){
    if(self==NULL) return NULL;
    self->_code+=1;
}
void huffcode_lshift(huffcode self,size_t nums){
    if(self==NULL) return NULL;
    self->_code<<=nums;
    self->_size+=nums;
}
void huffcode_rshift(huffcode self,size_t nums){
    if(self==NULL) return NULL;
    self->_code>>=nums;
    self->_size-=nums;
}
interfaces huffcode_create_inters(){
    return new_interfaces(1,
        new_interface(sizeof(HuffCode),NULL,"ip",huffcode_init,huffcode_print)
    );
}