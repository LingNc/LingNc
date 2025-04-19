#include "sqlist.h"
#include <stdlib.h>
#include <string.h>

// 初始化函数
sqlist new_sqlist() {
    sqlist list = (sqlist)malloc(sizeof(SqList));
    if (list == NULL) {
        return NULL;
    }

    if (sqlist_init(list) != OK) {
        free(list);
        return NULL;
    }

    return list;
}

Status sqlist_init(sqlist list) {
    if (list == NULL) {
        return ERROR;
    }

    // 初始容量为10
    list->_capacity = 10;
    list->_length = 0;
    list->_elemsize = sizeof(ElemType);

    list->_data = (ElemType*)malloc(list->_capacity * list->_elemsize);
    if (list->_data == NULL) {
        return ERROR;
    }

    return OK;
}

// 获取大小
size_t sqlist_size(sqlist list) {
    if (list == NULL) {
        return 0;
    }
    return list->_capacity;
}

size_t sqlist_lenth(sqlist list) {
    if (list == NULL) {
        return 0;
    }
    return list->_length;
}

// 获取元素
ElemType sqlist_get(sqlist list, size_t index) {
    if (list == NULL || index >= list->_length) {
        // 返回一个默认值，实际应用中可能需要其他错误处理
        return 0;
    }
    return list->_data[index];
}

elemtype sqlist_at(sqlist list, size_t index) {
    if (list == NULL || index >= list->_length) {
        return NULL;
    }
    return &(list->_data[index]);
}

// 设置元素
Status sqlist_set(sqlist list, size_t index, ElemType value) {
    if (list == NULL || index >= list->_length) {
        return ERROR;
    }
    list->_data[index] = value;
    return OK;
}

// 重设大小
Status sqlist_resize(sqlist list, size_t newsize) {
    if (list == NULL) {
        return ERROR;
    }

    ElemType* newdata = (ElemType*)realloc(list->_data, newsize * list->_elemsize);
    if (newdata == NULL && newsize > 0) {
        return ERROR;
    }

    list->_data = newdata;
    list->_capacity = newsize;

    // 如果新容量小于当前长度，则截断长度
    if (newsize < list->_length) {
        list->_length = newsize;
    }

    return OK;
}

// 插入元素
Status sqlist_insert(sqlist list, size_t index, ElemType value) {
    if (list == NULL || index > list->_length) {
        return ERROR;
    }

    // 检查是否需要扩容
    if (list->_length >= list->_capacity) {
        // 扩容为原来的2倍
        if (sqlist_resize(list, list->_capacity * 2) != OK) {
            return ERROR;
        }
    }

    // 将index及之后的元素后移一位
    for (size_t i = list->_length; i > index; i--) {
        list->_data[i] = list->_data[i - 1];
    }

    // 在index位置插入元素
    list->_data[index] = value;
    list->_length++;

    return OK;
}

// 删除元素
Status sqlist_delete(sqlist list, size_t index) {
    if (list == NULL || index >= list->_length) {
        return ERROR;
    }

    // 将index后的元素前移一位
    for (size_t i = index; i < list->_length - 1; i++) {
        list->_data[i] = list->_data[i + 1];
    }

    list->_length--;

    // 如果长度小于容量的1/4，则缩小容量为原来的一半
    if (list->_length < list->_capacity / 4 && list->_capacity > 10) {
        sqlist_resize(list, list->_capacity / 2);
    }

    return OK;
}

// 尾部添加
Status sqlist_push_back(sqlist list, ElemType value) {
    return sqlist_insert(list, list->_length, value);
}

// 尾部删除
Status sqlist_pop_back(sqlist list) {
    if (list == NULL || list->_length == 0) {
        return ERROR;
    }
    return sqlist_delete(list, list->_length - 1);
}

// 释放
void sqlist_free(sqlist list) {
    if (list == NULL) {
        return;
    }

    if (list->_data != NULL) {
        free(list->_data);
        list->_data = NULL;
    }

    free(list);
}
