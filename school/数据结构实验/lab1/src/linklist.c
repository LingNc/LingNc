#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>

// 初始化结点
node new_node(ElemType val) {
    node n = (node)malloc(sizeof(Node));
    if(n == NULL) return NULL;
    n->data = val;
    n->next = NULL;
    return n;
}

// 初始化节点（别名，兼容头文件）
node node_init(ElemType val) { return new_node(val); }

// 下一个节点
node node_next(node* val) {
    if(*val == NULL) return NULL;
    *val = (*val)->next;
    return *val;
}

// 获取节点值
elemtype node_val(node val) {
    if(val == NULL) return NULL;
    return &val->data;
}

// 初始化链表
linklist new_linklist() {
    linklist self = (linklist)malloc(sizeof(Linklist));
    if(self == NULL) return NULL;
    if(linklist_init(self) != OK) {
        free(self);
        return NULL;
    }
    return self;
}

Status linklist_init(linklist self) {
    if(self == NULL) return ERROR;
    self->_length = 0;
    self->_root = NULL;
    self->_head = NULL;
    self->_tail = NULL;
    return OK;
}

node linklist_bgein(linklist self) {
    if(self == NULL) return NULL;
    return self->_root;
}

node linklist_end(linklist self) {
    if(self == NULL) return NULL;
    return self->_tail;
}

node linklist_root(linklist self) {
    if(self == NULL) return NULL;
    return self->_root;
}

size_t linklist_size(linklist self) { return linklist_length(self); }

size_t linklist_length(linklist self) {
    if(self == NULL) return 0;
    return self->_length;
}

ElemType linklist_get(linklist self, size_t pos) {
    node n = linklist_at(self, pos);
    if(n == NULL) {
        perror("访问了不该访问的位置");
        exit(1);
    }
    return n->data;
}

node linklist_at(linklist self, size_t pos) {
    if(self == NULL || pos >= self->_length) return NULL;
    node curr = self->_root;
    size_t i = 0;
    while(curr && i < pos) {
        curr = curr->next;
        i++;
    }
    return curr;
}

Status linklist_set(linklist self, size_t pos, ElemType val) {
    node n = linklist_at(self, pos);
    if(n == NULL) return ERROR;
    n->data = val;
    return OK;
}

Status linklist_push_back(linklist self, ElemType val) {
    if(self == NULL) return ERROR;
    node n = new_node(val);
    if(n == NULL) return ERROR;
    if(self->_root == NULL) {
        self->_root = n;
        self->_head = n;
        self->_tail = n;
    } else {
        self->_tail->next = n;
        self->_tail = n;
    }
    self->_length++;
    return OK;
}

Status linklist_pop_back(linklist self) {
    if(self == NULL || self->_root == NULL) return ERROR;
    if(self->_length == 1) {
        free(self->_root);
        self->_root = self->_head = self->_tail = NULL;
        self->_length = 0;
        return OK;
    }
    node prev = self->_root;
    while(prev->next && prev->next != self->_tail) {
        prev = prev->next;
    }
    free(self->_tail);
    prev->next = NULL;
    self->_tail = prev;
    self->_length--;
    if(self->_length == 1) self->_head = self->_tail;
    return OK;
}

Status linklist_push_front(linklist self, ElemType val) {
    if(self == NULL) return ERROR;
    node n = new_node(val);
    if(n == NULL) return ERROR;
    n->next = self->_root;
    self->_root = n;
    if(self->_length == 0) {
        self->_head = n;
        self->_tail = n;
    } else {
        self->_head = n;
    }
    self->_length++;
    return OK;
}

node linklist_find(linklist self, ElemType val) {
    if(self == NULL) return NULL;
    node curr = self->_root;
    while(curr) {
        if(elemtype_compare(&curr->data, &val)) return curr;
        curr = curr->next;
    }
    return NULL;
}

Status linklist_delete(linklist self, size_t pos) {
    if(self == NULL || self->_root == NULL || pos >= self->_length) return ERROR;
    node to_delete = NULL;
    if(pos == 0) {
        to_delete = self->_root;
        self->_root = self->_root->next;
        if(self->_length == 1) self->_tail = NULL;
        self->_head = self->_root;
    } else {
        node prev = self->_root;
        for(size_t i = 0; i < pos - 1; ++i) prev = prev->next;
        to_delete = prev->next;
        prev->next = to_delete->next;
        if(to_delete == self->_tail) self->_tail = prev;
    }
    free(to_delete);
    self->_length--;
    if(self->_length == 0) self->_head = self->_tail = self->_root = NULL;
    return OK;
}

Status linklist_free(linklist self) {
    if(self == NULL) return ERROR;
    node curr = self->_root;
    while(curr) {
        node temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(self);
    return OK;
}