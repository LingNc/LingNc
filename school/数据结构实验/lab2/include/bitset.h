#ifndef BITSET_H
#define BITSET_H

#include "any.h"
#include "tools.h"
#include "interface.h"
#include <stdbool.h>

// 防止分配巨量内存
#define BITSET_MAX_SIZE 8*MB(1)

// Bitset
struct Bitset{
    // 1 字节指针
    byte _data;
    // 现在存储位数量
    size_t _size;
    // 容量 字节
    size_t _capacity;
}; // Bitset
typedef struct Bitset Bitset;
typedef Bitset *bitset;

bitset new_bitset(size_t size);
bitset bitset_init(bitset self,interface inter);
any bitset_copy(bitset self,bitset other);
bool bitset_get(bitset self,size_t index);
any bitset_set(bitset self,size_t index,bool value);
any bitset_clear(bitset self);
void bitset_print(bitset self);
any free_bitset(bitset self);
interface bitset_create_inter();
#endif // BITSET_H