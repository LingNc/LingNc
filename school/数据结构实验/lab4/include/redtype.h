#ifndef REDTYPE_H
#define REDTYPE_H

#define MAXSIZE 100 /*参加排序元素的最大个数*/
typedef int KeyType;
typedef int InfoType; /*其他信息类型*/

struct RedType{
    KeyType  key;
    InfoType  otherinfo;  // 其他字段（自行设计）
};

typedef struct RedType RedType;
typedef RedType *redtype;

#endif // REDTYPE_H