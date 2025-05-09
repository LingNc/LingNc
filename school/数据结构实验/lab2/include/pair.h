#ifndef PAIR_H
#define PAIR_H

#include "any.h"
#include "exception.h"
#include "interface.h"

// 对 inter
struct PiarInter{
    interface first,second;
}; // Pair_inter
typedef struct PiarInter PairInter;
typedef PairInter *pairinter;

// new
pairinter new_pairinter(interface first,interface second);
any pairinter_init(pairinter sel,interface inter);
any pairinter_clear(pairinter self);
any free_pairinter(pairinter self);
// interface pairinter_create_inter();

// 对
struct Pair{
    any first,second;
    pairinter _pinter;
}; // Pair

typedef struct Pair Pair;
typedef Pair *pair;

// new 接受 pair_inter
pair new_pair(any first,any second, pairinter pinter);
// any pair_init(pair self,interface inter);
any pair_clear(pair self);
any pair_copy(pair slef,pair other);
any free_pair(pair self);
interface pair_create_inter();

#endif //PAIR_H