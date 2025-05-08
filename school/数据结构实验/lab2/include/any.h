#ifndef ANY_H
#define ANY_H

#include <stdint.h>

// 泛型定义
typedef void *any,*self;
// 字节指针
typedef uint8_t *byte,(*byte2)[2],(*byte3)[3],(*byte4)[4],(*byte5)[5],(*byte6)[6],(*byte7)[7],(*byte8)[8];

#endif //ANY_H