#ifndef ANY_H
#define ANY_H

#include <stdint.h>

// 泛型定义
typedef void *any,*self;
typedef const void *c_any,*c_self;

// 字节指针
typedef uint8_t  Byte;
typedef uint16_t Byte2;
typedef uint32_t Byte4;
typedef uint64_t Byte8;
typedef Byte *byte,
            (*byte2)[2],
            (*byte3)[3],
            (*byte4)[4],
            (*byte5)[5],
            (*byte6)[6],
            (*byte7)[7],
            (*byte8)[8];
// utf8 定义
typedef Byte8 utf8;

// 变长指针
#define pointer(x) typeof(Byte (*)[x])
// 静态强制类型转换
#define cast(type,x) ((type)x)
// 访问指针按照指定类型强制获取值
#define visitp_cast(type,x) (*cast(type*,x))
// 内存重解释强制转换
#define reinter_cast(type,x) (*cast(type*,&x))

#endif //ANY_H