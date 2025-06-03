#ifndef REDTYPE_H
#define REDTYPE_H

#define MAXSIZE 100 /*参加排序元素的最大个数*/
typedef int KeyType;
typedef int InfoType; /*其他信息类型*/

struct RedType{
    KeyType  key;
    InfoType  otherinfo;  // 用于验证稳定性的原始位置信息
};

typedef struct RedType RedType;
typedef RedType *redtype;

// 排序统计信息
struct SortStats{
    int compare_count;  // 比较次数
    int move_count;     // 移动次数
};
typedef struct SortStats SortStats;
typedef SortStats *sortstats;

#endif // REDTYPE_H