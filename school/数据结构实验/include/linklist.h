#ifndef LINKLIST_H
#define LINKLIST_H

#include "type1.h"
#include"error.h"
struct Node{
    ElemType data;
    struct Node *next;
};

typedef struct Node Node,Linklist;
typedef Node *node,*linklist;

// 初始化结点
node new_node(ElemType);
// 初始化节点
node new_node_init(ElemType);
// 初始化函数
linklist new_linklist();
Status linklist_init(linklist);
// 获取大小
size_t linklist_size(linklist);
size_t linklist_length(linklist);
// 获取元素
ElemType linklist_get(linklist,size_t);
node linklist_at(linklist,size_t);
// 设置元素
Status linklist_set(linklist,size_t,ElemType);
// 尾插
Status linklist_push_back(linklist,ElemType);
// 尾删
Status linklist_pop_back(linklist);
// 头插
Status linklist_push_front(linklist,ElemType);
// 查找
node linklist_find(linklist,ElemType);
// 删除
Status linklist_delete(linklist,size_t);
// 释放
Status linklist_free(linklist);

#endif // LINKLIST_H
