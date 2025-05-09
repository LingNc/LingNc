#ifndef PAIR_H
#define PAIR_H

#include "any.h"
#include "exception.h"
#include "interface.h"

// 对 inter
struct Piar_inter{
    interface first,second;
}; // Pair_inter
typedef struct Piar_inter Pair_inter;
typedef Pair_inter *pair_inter;

// new
pair_inter new_pair_inter(interface first,interface second);
any pair_inter_init(pair_inter sel,interface inter);
any pair_inter_clear(pair_inter self);
any free_pair_inter(pair_inter self);

// 对
struct Pair{
    any first,second;
    pair_inter _inter;
}; // Pair

typedef struct Pair Pair;
typedef Pair *pair;

// new 接受 pair_inter
pair new_pair(any first,any second,any inter);
any pair_init(pair self,any inter);
any pair_clear(pair self);
any pair_copy(pair slef,pair other);
any free_pair(pair self);
interface pair_create_inter();

#endif //PAIR_H