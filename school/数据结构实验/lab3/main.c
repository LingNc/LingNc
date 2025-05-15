#include "graph.h"
#include "heap.h"
#include "pair.h"
#include <stdio.h>
#include <limits.h>
#include <math.h>

// 静态管理pair接口
// pair<double,int>
static interfaces g_pair_inter=NULL;
static interfaces g_in_pair_inter=NULL;
#define pair_r(_first,_second) new_pair_r(_first,_second,g_in_pair_inter)

// 初始化接口
void init_pair_inter(){
    if(!g_in_pair_inter){
        g_in_pair_inter=new_interfaces(NULL,2,
            new_interface(sizeof(double),NULL,""),
            new_interface(sizeof(int),NULL,"")
        );
    }
    if(!g_pair_inter){
        g_pair_inter=pair_create_inters();
    }
}
// 释放接口
void free_pair_inter(){
    if(g_pair_inter){
        free_interfaces(g_pair_inter);
        g_pair_inter=NULL;
    }
}

// 优先队列排序函数,按照距离小顶堆
// 数据类型: pair<double,int>
// pair<距离,节点编号>
bool min_cmp(c_any a,c_any b){
    return cast(pair,a)->first<cast(pair,b)->first;
}

// 浮点数的相等
#define double_eq(a,b) (fabs(a-b)<1e-6)

// Dijkstra算法
double Dijkstra(algraph graph,int start,int end){
    // 初始化堆 pair<double,int> pair<距离，节点编号>
    priority_queue h=new_heap(g_pair_inter,min_cmp);
    // 插入第一个元素
    heap_push(h,&pair_r(0,start));
    double *dist=graph->dist;
    bool *st=graph->st;
    dist[start]=0;

    // pair t=new_pair(NULL,NULL,g_pair_inter);
    while(!heap_empty(h)){
        // 取出节点
        int now=visitp_cast(int,cast(pair,heap_top(h))->second);
        heap_pop(h);
        // 检查是否访问过
        if(st[now]) continue;
        st[now]=true;
        // 遍历从这个节点可达的节点更新最小距离
        sqlist lp=algraph_visit(graph,now);
        int size=sqlist_size(lp);
        for(int i=0;i<size;i++){
            // arcnode
            arcnode it=sqlist_at(lp,i);
            // 更新最小距离
            if(dist[it->adjvex]>dist[now]+it->weight){
                dist[it->adjvex]=dist[now]+it->weight;
                heap_push(h,&pair_r(dist[it->adjvex],it->adjvex));
            }
        }
    }
    // 返回最小距离
    return (double_eq(dist[end],1e9))?-1:dist[end];
}

int main(){
    // 初始化接口
    init_pair_inter();
    // 节点数量，边数量
    int vex,arc;
    printf("请输入节点数量和边数量:\n");
    scanf("%d%d",&vex,&arc);
    // 创建路程最短
    algraph disGraph=new_algraph(vex,arc,UDN);
    // 时间最短
    algraph timeGraph=new_algraph(vex,arc,UDN);
    // a和b节点间的一条边，s是长度，v是速度
    int a,b;
    double s,v;
    printf("请输入边的信息 a:节点1 b:节点2 c:长度 d:平均速度:\n");
    for(int i=0;i<arc;i++){
        scanf("%d%d%lf%lf",&a,&b,&s,&v);
        if(a>vex||b>vex){
            Exception e=new_exception(WARRING,"输入的图节点超出范围,请重新输入");
            printf("%s\n",e.msg);
            i--;
            continue;
        }
        // 路程图
        algraph_add(disGraph,a,b,s);
        // 将时间作为权，求时间图
        algraph_add(timeGraph,a,b,s/v);
    }
    // 起点和终点
    int start,end;
    bool exit=true;
    // 根据用户输入出发点和结束点来找到最短的路程和用时
    while(exit){
        printf("请输入起点和终点:\n");
        scanf("%d%d",&start,&end);
        if(start>vex||end>vex){
            Exception e=new_exception(WARRING,"输入的图节点超出范围,请重新输入");
            printf("%s\n",e.msg);
            continue;
        }
        // 计算最短路程
        double dis=Dijkstra(disGraph,start,end);
        // 计算最短时间
        double time=Dijkstra(timeGraph,start,end);
        if(double_eq(dis,-1)||double_eq(dis,-1))
            printf("从%d到%d没有路径!\n",start,end);
        else{
            printf("从%d到%d的最短路程为:%.2lf\n",start,end,dis);
            printf("从%d到%d的最短时间为:%.2lf\n",start,end,time);
        }
        printf("是否继续计算?(y/n)[default=y]\n");
        char c;
        scanf(" %c",&c);
        if(c=='n'||c=='N'){
            exit=false;
            printf("退出计算!\n");
        }
    }
    // 释放资源
    free_algraph(&disGraph);
    free_algraph(&timeGraph);
    free_pair_inter();
    return 0;
}