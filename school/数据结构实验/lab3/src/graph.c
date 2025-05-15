#include "graph.h"
#include <limits.h>
#include <stdio.h>

// 静态管理接口
static interfaces g_arcnode_inter=NULL;

// 创建一个图结点
arcnode new_arcnode(int adjvex,int weight){
    arcnode self=malloc(sizeof(ArcNode));
    if(!self) return NULL;
    self->adjvex=adjvex;
    self->weight=weight;
    return self;
}

// 图的初始化
Exception algraph_init(algraph self,int vexnum,int arcnum,GraphKind kind){
    if(self==NULL) return new_exception(ERROR,"algraph_init: 传入self指针为空!");
    self->vexnum=vexnum;
    self->arcnum=arcnum;
    self->kind=kind;
    // 分配动态内存空间
    self->st=malloc(sizeof(bool)*(vexnum+1));
    self->dist=malloc(sizeof(double)*(vexnum+1));
    // 初始化
    for(int i=0;i<vexnum;i++){
        self->st[i]=false;
        self->dist[i]=1e9;
    }
    // 初始化arcnode接口
    if(!g_arcnode_inter){
        g_arcnode_inter=new_interfaces(NULL,1,
            new_interface(sizeof(ArcNode),NULL,""));
    }
    // 初始化邻接表
    Exception e=sqlist_init(&self->_list,g_arcnode_inter);
    return new_exception(SUCCESS,"");
}

// 新建图
algraph new_algraph(int vexnum,int arcnum,GraphKind kind){
    algraph self=malloc(sizeof(ALGraph));
    if(!self) return NULL;
    Exception e=algraph_init(self,vexnum,arcnum,kind);
    if(e.status!=SUCCESS){
        free(self);
        fprintf(stderr,"algraph_init: init ");
        perror(e.msg);
        return NULL;
    }
    return self;
}

// 清空图
any algraph_clear(algraph self){
    if(!self) return NULL;
    // 清空邻接表
    sqlist_clear(&self->_list);
    // 清空访问数组
    sfree(&self->st);
    // 清空距离数组
    sfree(&self->dist);
    self->vexnum=0;
    self->arcnum=0;
    self->kind=0;
    return self;
}

// 释放图
any free_algraph(algraph *self){
    if(self==NULL) return NULL;
    // 清空图
    algraph_clear(self);
    // 释放静态接口
    if(g_arcnode_inter) free_interfaces(g_arcnode_inter);
    g_arcnode_inter=NULL;
    // 释放图
    sfree(self);
}

// 带权加边
void algraph_add(algraph self,int i,int j,double weight){
    // 添加节点 有向图
    // 添加边 从 i -> j
    sqlist_push_back(sqlist_at(self,i),&arcnode_r(j,weight));
    // 如果是无向图,添加边 从 j -> i
    if(self->kind==UDN||self->kind==UDG){
        sqlist_push_back(sqlist_at(self,j),&arcnode_r(i,weight));
    }
}

// 访问第node个节点的邻接表
sqlist algraph_visit(algraph self,int node){
    return sqlist_at(&self->_list,node);
}