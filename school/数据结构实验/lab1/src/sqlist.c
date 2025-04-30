#include "sqlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 初始化函数
sqlist new_sqlist() {
    sqlist self = (sqlist)malloc(sizeof(SqList));
    if(self == NULL) {
        return NULL;
    }

    if(sqlist_init(self) != OK) {
        free(self);
        return NULL;
    }

    return self;
}

Status sqlist_init(sqlist self) {
    if(self == NULL) {
        return ERROR;
    }

    // 初始容量为10
    self->_capacity = 10;
    self->_length = 0;
    self->_elemsize = sizeof(ElemType);

    self->_data = (ElemType *)malloc(self->_capacity * self->_elemsize);
    if(self->_data == NULL) {
        return ERROR;
    }

    return OK;
}

// 获取大小
size_t sqlist_size(sqlist self) {
    if(self == NULL) {
        return 0;
    }
    return self->_capacity;
}

size_t sqlist_length(sqlist self) {
    if(self == NULL) {
        return 0;
    }
    return self->_length;
}

// 获取元素
ElemType sqlist_get(sqlist self, size_t pos) {
    if(self == NULL || pos >= self->_length) {
        // 访问了不该访问的位置
        perror("访问了不该访问的位置");
        exit(1);
    }
    return self->_data[pos];
}

elemtype sqlist_at(sqlist self, size_t pos) {
    if(self == NULL || pos >= self->_length) {
        return NULL;
    }
    return &(self->_data[pos]);
}

// 设置元素
Status sqlist_set(sqlist self, size_t index, ElemType val) {
    if(self == NULL || index >= self->_length) {
        return ERROR;
    }
    self->_data[index] = val;
    return OK;
}

// 重设大小
Status sqlist_resize(sqlist self, size_t new_size) {
    if(self == NULL) {
        return ERROR;
    }

    ElemType *newdata = (ElemType *)realloc(self->_data, new_size * self->_elemsize);
    if(newdata == NULL && new_size > 0) {
        return ERROR;
    }

    self->_data = newdata;
    self->_capacity = new_size;

    // 如果新容量小于当前长度，则截断长度
    if(new_size < self->_length) {
        self->_length = new_size;
    }

    return OK;
}

// 插入元素
Status sqlist_insert(sqlist self, size_t pos, ElemType val) {
    if(self == NULL || pos > self->_length) {
        return ERROR;
    }

    // 检查是否需要扩容
    if(self->_length >= self->_capacity) {
        // 扩容为原来的2倍
        if(sqlist_resize(self, self->_capacity * 2) != OK) {
            return ERROR;
        }
    }

    // 将pos及之后的元素后移一位
    for(size_t i = self->_length; i > pos; i--) {
        self->_data[i] = self->_data[i - 1];
    }

    // 在pos位置插入元素
    self->_data[pos] = val;
    self->_length++;

    return OK;
}

// 删除元素
Status sqlist_delete(sqlist self, size_t pos) {
    if(self == NULL || pos >= self->_length) {
        return ERROR;
    }

    // 将pos后的元素前移一位
    for(size_t i = pos; i < self->_length - 1; i++) {
        self->_data[i] = self->_data[i + 1];
    }

    self->_length--;

    // 如果长度小于容量的1/4，则缩小容量为原来的一半
    if(self->_length < self->_capacity / 4 && self->_capacity > 10) {
        sqlist_resize(self, self->_capacity / 2);
    }

    return OK;
}

// 尾部添加
Status sqlist_push_back(sqlist self, ElemType val) {
    return sqlist_insert(self, self->_length, val);
}

// 尾部删除
Status sqlist_pop_back(sqlist self) {
    if(self == NULL || self->_length == 0) {
        return ERROR;
    }
    return sqlist_delete(self, self->_length - 1);
}

// 释放
void sqlist_free(sqlist self) {
    if(self == NULL) {
        return;
    }

    if(self->_data != NULL) {
        free(self->_data);
        self->_data = NULL;
    }

    free(self);
}
