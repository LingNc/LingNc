#ifndef ANY_H
#define ANY_H

#include <stdint.h>

// 泛型定义
typedef void *any,*self;
// 字节指针
typedef uint8_t Byte;
typedef Byte *byte,(*byte2)[2],(*byte3)[3],(*byte4)[4],(*byte5)[5],(*byte6)[6],(*byte7)[7],(*byte8)[8];
// utf8 定义
typedef uint32_t utf8;

#endif //ANY_H