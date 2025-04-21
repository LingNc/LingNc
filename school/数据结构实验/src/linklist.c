#include "linklist.h"
#include "type.h"
#include <stdio.h>
#include <stdlib.h>

// 初始化节点
node new_node(ElemType data) {
    node n = (node)malloc(sizeof(Node));
    if(n == NULL) {
        return NULL;
    }
    n->data = data;
    n->next = NULL;
    return n;
}

// 初始化节点
node new_node_init(ElemType data) { return new_node(data); }

// 初始化链表
linklist new_linklist() {
    linklist list = (linklist)malloc(sizeof(Linklist));
    if(list == NULL) {
        return NULL;
    }

    if(linklist_init(list) != OK) {
        free(list);
        return NULL;
    }

    return list;
}

Status linklist_init(linklist list) {
    if(list == NULL) {
        return ERROR;
    }

    // 头节点不存储数据，next为NULL
    list->data = *new_elemtype();
    list->next = NULL;

    return OK;
}

// 获取链表大小
size_t linklist_size(linklist list) { return linklist_length(list); }

size_t linklist_length(linklist list) {
    if(list == NULL) {
        return 0;
    }

    size_t count = 0;
    node curr = list->next;

    while(curr != NULL) {
        count++;
        curr = curr->next;
    }

    return count;
}

// 获取第index个元素的值
ElemType linklist_get(linklist list, size_t index) {
    node n = linklist_at(list, index);
    if(n == NULL) {
        // 访问了不该访问的位置
        perror("访问了不该访问的位置");
        exit(1);
    }
    return n->data;
}

// 获取第index个节点
node linklist_at(linklist list, size_t index) {
    if(list == NULL) {
        return NULL;
    }

    node curr = list->next;
    size_t i = 0;

    while(curr != NULL && i < index) {
        curr = curr->next;
        i++;
    }

    return curr; // 如果index超出范围，返回NULL
}

// 设置第index个元素的值
Status linklist_set(linklist list, size_t index, ElemType value) {
    node n = linklist_at(list, index);
    if(n == NULL) {
        return ERROR;
    }

    n->data = value;
    return OK;
}

// 尾插
Status linklist_push_back(linklist list, ElemType value) {
    if(list == NULL) {
        return ERROR;
    }

    // 创建新节点
    node new = new_node(value);
    if(new == NULL) {
        return ERROR;
    }

    // 找到最后一个节点
    node curr = list;
    while(curr->next != NULL) {
        curr = curr->next;
    }

    // 在尾部添加新节点
    curr->next = new;

    return OK;
}

// 尾删
Status linklist_pop_back(linklist list) {
    if(list == NULL || list->next == NULL) {
        return ERROR;
    }

    // 找到倒数第二个节点
    node curr = list;
    while(curr->next != NULL && curr->next->next != NULL) {
        curr = curr->next;
    }

    // 删除最后一个节点
    free(curr->next);
    curr->next = NULL;

    return OK;
}

// 头插
Status linklist_push_front(linklist list, ElemType value) {
    if(list == NULL) {
        return ERROR;
    }

    // 创建新节点
    node new = new_node(value);
    if(new == NULL) {
        return ERROR;
    }

    // 在头部插入新节点
    new->next = list->next;
    list->next = new;

    return OK;
}

// 查找元素
node linklist_find(linklist list, ElemType value) {
    if(list == NULL) {
        return NULL;
    }

    node curr = list->next;

    while(curr != NULL) {
        if(curr->data == value) {
            return curr;
        }
        curr = curr->next;
    }

    return NULL; // 未找到
}

// 删除第index个元素
Status linklist_delete(linklist list, size_t index) {
    if(list == NULL || list->next == NULL) {
        return ERROR;
    }

    // 特殊处理: 删除第0个元素
    if(index == 0) {
        node temp = list->next;
        list->next = temp->next;
        free(temp);
        return OK;
    }

    // 找到第index-1个节点
    node prev = list;
    size_t i = 0;

    while(prev->next != NULL && i < index) {
        prev = prev->next;
        i++;
    }

    // 如果找到了第index-1个节点，并且它有下一个节点
    if(i == index - 1 && prev->next != NULL) {
        node temp = prev->next;
        prev->next = temp->next;
        free(temp);
        return OK;
    }

    return ERROR; // index超出范围
}

// 释放链表
Status linklist_free(linklist list) {
    if(list == NULL) {
        return ERROR;
    }

    // 释放所有节点
    node curr = list->next;
    node temp;

    while(curr != NULL) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }

    // 释放头节点
    free(list);

    return OK;
}