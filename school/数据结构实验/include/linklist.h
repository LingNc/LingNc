#ifndef LINKLIST_H
#define LINKLIST_H

#include "error.h"
#include "type.h"
#include <stddef.h>
struct Node {
    ElemType data;
    struct Node *next;
};

typedef struct Node Node;
typedef Node *node;

struct LinkList{
    size_t _length;
    node _root;
    node _head;
    node _tail;
};
typedef struct LinkList Linklist;
typedef Linklist *linklist;

// 初始化结点
node new_node(ElemType val);
// 初始化节点
node node_init(ElemType val);
// 下一个节点
node node_next(node val);
// 获取节点值
elemtype node_val(node val);
// 初始化函数
linklist new_linklist();
Status linklist_init(linklist self);
// 获取头节点
node linklist_bgein(linklist self);
// 获取尾节点
node linklist_end(linklist self);
// 获取根节点
node linklist_root(linklist self);
// 获取大小
size_t linklist_size(linklist self);
size_t linklist_length(linklist self);
// 获取元素
ElemType linklist_get(linklist self, size_t pos);
node linklist_at(linklist self, size_t pos);
// 设置元素
Status linklist_set(linklist self, size_t pos, ElemType val);
// 尾插
Status linklist_push_back(linklist self, ElemType val);
// 尾删
Status linklist_pop_back(linklist self);
// 头插
Status linklist_push_front(linklist self, ElemType val);
// 查找
node linklist_find(linklist self, ElemType val);
// 删除
Status linklist_delete(linklist self, size_t pos);
// 释放
Status linklist_free(linklist self);

#endif // LINKLIST_H
