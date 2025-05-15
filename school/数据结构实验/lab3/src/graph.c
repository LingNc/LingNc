#include "graph.h"
#include "tools.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// 静态管理接口
// static interfaces g_arcnode_inter=NULL;
// static interfaces g_sqlist_inter=NULL;

// 创建一个图结点
arcnode new_arcnode(int adjvex,double weight){
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
    self->_arcnode_inter=new_interfaces(NULL,1,
        new_interface(sizeof(ArcNode),NULL,""));
    self->_sqlist_inter=sqlist_create_inter(self->_arcnode_inter);
    // 初始化邻接表
    Exception e=sqlist_init(&self->_list,self->_sqlist_inter);
    // 初始化邻接表每个表
    sqlist_resize(&self->_list,vexnum+1);
    return e;
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
void free_algraph(algraph *self){
    if(*self==NULL) return;
    // 清空图
    algraph_clear(*self);
    // 释放静态接口
    free_interfaces((*self)->_arcnode_inter);
    free_interfaces((*self)->_sqlist_inter);
    // 释放图
    sfree(self);
}

// 带权加边
void algraph_add(algraph self,int i,int j,double weight){
    // 添加节点 有向图
    // 添加边 从 i -> j
    sqlist_push_back(sqlist_at(&self->_list,i),&arcnode_r(j,weight));
    // 如果是无向图,添加边 从 j -> i
    if(self->kind==UDN||self->kind==UDG){
        sqlist_push_back(sqlist_at(&self->_list,j),&arcnode_r(i,weight));
    }
}

// 访问第node个节点的邻接表
sqlist algraph_visit(algraph self,int node){
    return sqlist_at(&self->_list,node);
}