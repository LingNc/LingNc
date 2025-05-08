#ifndef PAIR_H
#define PAIR_H

#include "any.h"
#include "exception.h"
#include "interface.h"
// 对
struct Pair{
    any first,second;
}; // Pair

typedef struct Pair Pair;
typedef Pair *pair;

// new
pair new_pair(any first,any second);
exception pair_init(pair self,interface inter);
exception pair_clear(pair self);
exception free_pair(pair self);
interface pair_create_inter();

#endif //PAIR_H