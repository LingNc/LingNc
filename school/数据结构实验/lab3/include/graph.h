#ifndef GRAPH_H
#define GRAPH_H

#include "sqlist.h"

//图结点
struct ArcNode{
    // 当前节点
    int adjvex;
    //边的权值
    double weight;
}; // ArcNode
typedef struct ArcNode ArcNode;
typedef ArcNode *arcnode;

// 创建一个图结点
arcnode new_arcnode(int adjvex,double weight);
// 创建右值节点
#define arcnode_r(a,b) ((ArcNode){.adjvex=a,.weight=b})

// 邻接表(采用sqlist动态数组实现)
typedef SqList AdjList;
typedef AdjList *adjlist;

// 图的类型
enum GraphKind{
    // 有向无权图
    DG=1,
    // 有向带权图
    DN,
    // 无向无权图
    UDG,
    // 无向带权图
    UDN,
};
typedef enum GraphKind GraphKind;

// 图
struct ALGraph{
    // 数据类型: SqList<SqList<ArcNode>>
    AdjList _list;
    // 记录是否访问过
    bool *st;
    // 记录权最小值
    double *dist;
    // 顶点的实际数
    int vexnum;
    // 边的实际数
    int arcnum;
    // 图的类型
    // 1:有向无权图
    // 2:有向带权图
    // 3:无向无权图
    // 4:无向带权图
    GraphKind kind;
}; // ALGraph
typedef struct ALGraph ALGraph;
typedef ALGraph *algraph;

// 新建图
algraph new_algraph(int vexnum,int arcnum,GraphKind kind);
// 图的初始化
Exception algraph_init(algraph self,int vexnum,int arcnum,GraphKind kind);
// 清空图
any algraph_clear(algraph self);
// 释放图
any free_algraph(algraph *self);
// 带权加边
void algraph_add(algraph self,int i,int j,int weight);
// 访问第node个节点的邻接表
sqlist algraph_visit(algraph self,int node);

#endif // GRAPH_H