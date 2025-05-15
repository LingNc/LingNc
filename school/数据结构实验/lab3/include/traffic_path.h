#ifndef GRAPH_PATH_H
#define GRAPH_PATH_H

// 存储路径信息
struct Path{
    int* path;
    int length;
};
typedef struct Path Path;
typedef Path *path;

// 初始化路径
path new_path(int size);
// 打印路径
void print_path(path path,const char *pathType,double pathValue);
// 释放路径
void free_path(path* path);

#endif // GRAPH_PATH_H