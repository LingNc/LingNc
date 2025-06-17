#include "huffcode.h"
#include <stdlib.h>
#include <stdio.h>

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
    printf("HuffCode: %lX %u\n", self->_code, self->_size);
}
bool huffcode_get(huffcode self,Byte index){
    if(self == NULL || index >= self->_size) return false;
    // 从最高有效位开始读取（位0是最高位）
    Byte bit_pos = self->_size - 1 - index;
    return (self->_code >> bit_pos) & 1;
}
any huffcode_set(huffcode self,Byte index,bool value){
    if(self==NULL||index>64) return NULL;
    index=64-self->_size+index;
    self->_code=(self->_code&~(1<<index))|(value<<index);
    return self;
}
void huffcode_inc(huffcode self){
    if(self==NULL) return;
    self->_code+=1;
}
void huffcode_lshift(huffcode self,size_t nums){
    if(self==NULL) return;
    self->_code<<=nums;
    self->_size+=nums;
}
void huffcode_rshift(huffcode self,size_t nums){
    if(self==NULL) return;
    self->_code>>=nums;
    self->_size-=nums;
}
interfaces huffcode_create_inters(){
    return new_interfaces(NULL, 1,
        new_interface(sizeof(HuffCode),NULL,"ip",huffcode_init,huffcode_print)
    );
}