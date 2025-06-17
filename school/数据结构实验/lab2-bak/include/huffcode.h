#ifndef HUFFCODE_H
#define HUFFCODE_H

#include "any.h"
#include "interface.h"
#include <stdint.h>
#include <stdbool.h>


struct HuffCode{
    uint64_t _code;
    Byte _size;
};
typedef struct HuffCode HuffCode;
typedef HuffCode *huffcode;

huffcode new_huffcode();
huffcode huffcode_init(huffcode self);
void huffcode_print(huffcode self);
bool huffcode_get(huffcode slef,Byte index);
any huffcode_set(huffcode self,Byte index,bool value);
// 增加一个数字
void huffcode_inc(huffcode self);
// 左移
void huffcode_lshift(huffcode self,size_t nums);
// 右移
void huffcode_rshift(huffcode self,size_t nums);
interfaces huffcode_create_inters();

#endif