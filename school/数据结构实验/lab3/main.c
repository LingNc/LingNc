#include "sqlist.h"
#include "pair.h"
#include <stdio.h>
#include <stdlib.h>

//表结点
typedef struct ArcNode ArcNode;
typedef ArcNode *arcnode;
struct ArcNode{
    int adjvex;
    //边的权值
    int weight;
}; // ArcNode

// 创建一个表结点
arcnode new_arcnode(int adjvex,int weight){
    arcnode self=malloc(sizeof(ArcNode));
    if(!self) return NULL;
    self->adjvex=adjvex;
    self->weight=weight;
    return self;
}
#define new_ArcNode(a,b) ((ArcNode){ \
    .adjvex=a,\
    .weight=b\
})
// 销毁节点
void destroy_arcnode(arcnode self){
    if(!self) return;
    free(self);
}

static interfaces g_arcnode_inter;

// 邻接表
typedef SqList AdjList;
typedef AdjList *adjlist;

// 图
struct ALGraph{
    // 数据类型: SqList<SqList<ArcNode>>
    AdjList _list;
    // 记录是否访问过
    bool *st;
    // 记录权最小值
    int *dist;
    //顶点的实际数，边的实际数
    int vexnum,arcnum;
    int kind;
}; // ALGraph
typedef struct ALGraph ALGraph;
typedef ALGraph *algraph;

// 初始化图
algraph new_algraph(int vexnum,int arcnum){
    algraph self=malloc(sizeof(ALGraph));
    if(!self) return NULL;
    self->vexnum=vexnum;
    self->arcnum=arcnum;
    self->kind=0;
    self->st=malloc(sizeof(bool)*(vexnum+1));
    self->dist=malloc(sizeof(int)*(vexnum+1));
    // 初始化
    for(int i=0;i<=vexnum;i++){
        self->st[i]=false;
        self->dist[i]=0;
    }
    // 创建节点的 interfaces
    g_arcnode_inter=new_interfaces(NULL,1,
        new_interface(sizeof(ArcNode),NULL,""));
    // 初始化邻接表
    Exception e=sqlist_init(&self->_list,g_arcnode_inter);
    if(e.status!=SUCCESS) {
        free(self);
        fprintf(stderr,"new_algraph: init ");
        perror(e.msg);
        return NULL;
    }
    return self;
}

// 带权加边
void algraph_add(algraph self,int i,int j,int weight){
    // 添加节点
    sqlist_push_back(sqlist_at(self,i),&new_ArcNode(j,weight));
}

// 优先队列排序函数,按照距离小顶堆
// 数据类型: pair<int,int>
// pair<距离,节点编号>
bool min_cmp(c_any a,c_any b){
    return cast(pair,a)->first < cast(pair,b)->first;
}

int main(){

    return 0;
}