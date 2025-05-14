#ifndef PAIR_H
#define PAIR_H

#include "any.h"
#include "exception.h"
#include "interface.h"

// 对
struct Pair{
    interfaces _inters;
    any first,second;
}; // Pair

typedef struct Pair Pair;
typedef Pair *pair;

// new 接受 pair_inter
pair new_pair(any first,any second,interfaces inters);
any pair_init(pair self,interfaces inters);
any pair_clear(pair self);
any pair_copy(pair self,pair other);
any pair_move(pair dest,pair src);
void pair_print(pair self);
any free_pair(pair self);
interfaces pair_create_inters();

#endif //PAIR_H