#include "heap.h"
#include "pair.h"
#include "traffic_ui.h"
#include "traffic_tools.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// 静态管理pair接口
// pair<double,int>
static interfaces g_pair_inter=NULL;
static interfaces g_in_pair_inter=NULL;
#define pair_r(_first, _second) new_pair_r(_first, _second, g_in_pair_inter)

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
#define double_eq(a, b) (fabs(a-b) < 1e-6)

// Dijkstra算法（返回路径）
path dijkstra_with_path(algraph graph,int start,int end,double *minDist){
    // 初始化前驱数组
    int *prev=(int *)malloc(sizeof(int)*(graph->vexnum+1));
    for(int i=0; i<=graph->vexnum; i++){
        prev[i]=-1; // -1表示没有前驱
        graph->st[i]=false;
        graph->dist[i]=1e9;
    }

    // 初始化堆 pair<double,int> pair<距离，节点编号>
    priority_queue h=new_heap(g_pair_inter,min_cmp);
    // 插入第一个元素
    heap_push(h,&pair_r(0,start));
    double *dist=graph->dist;
    bool *st=graph->st;
    dist[start]=0;

    while(!heap_empty(h)){
        // 取出节点
        int now=visitp_cast(int,cast(pair,heap_top(h))->second);
        heap_pop(h);
        // 检查是否访问过
        if(st[now]) continue;
        st[now]=true;

        // 如果找到终点，可以提前退出
        if(now==end) break;

        // 遍历从这个节点可达的节点更新最小距离
        sqlist lp=algraph_visit(graph,now);
        int size=sqlist_size(lp);
        for(int i=0; i<size; i++){
            // arcnode
            arcnode it=sqlist_at(lp,i);
            // 更新最小距离
            if(dist[it->adjvex]>dist[now]+it->weight){
                dist[it->adjvex]=dist[now]+it->weight;
                prev[it->adjvex]=now; // 记录前驱
                heap_push(h,&pair_r(dist[it->adjvex],it->adjvex));
            }
        }
    }

    // 返回最小距离
    *minDist=(double_eq(dist[end],1e9))?-1:dist[end];

    // 如果找不到路径
    if(double_eq(*minDist,-1)){
        free(prev);
        return NULL;
    }

    // 构建路径
    path path=new_path(graph->vexnum+1);
    int current=end;
    while(current!=-1){
        path->path[path->length++]=current;
        current=prev[current];
    }

    // 翻转路径（从起点到终点）
    for(int i=0; i<path->length/2; i++){
        int temp=path->path[i];
        path->path[i]=path->path[path->length-1-i];
        path->path[path->length-1-i]=temp;
    }

    free(prev);
    return path;
}

// 创建交通网络
void create_traffic_network(algraph *disGraph,algraph *timeGraph){
    print_title("创建交通网络");

    // 释放现有资源（如果有）
    if(*disGraph){
        free_algraph(disGraph);
    }
    if(*timeGraph){
        free_algraph(timeGraph);
    }

    // 节点数量，边数量
    int vex,arc;
    print("请输入节点数量: ");
    scanf("%d",&vex);

    if(vex<=0){
        printl("节点数量必须大于0！按任意键返回...");
        getchar();
        getchar();
        return;
    }

    print("请输入边数量: ");
    scanf("%d",&arc);

    if(arc<=0){
        printl("边数量必须大于0！按任意键返回...");
        getchar();
        getchar();
        return;
    }

    // 创建路程最短图
    *disGraph=new_algraph(vex,arc,UDN);
    // 创建时间最短图
    *timeGraph=new_algraph(vex,arc,UDN);

    print_gap(1);
    printl("请输入每条边的信息:");
    printl("格式: [起点] [终点] [距离(km)] [速度(km/h)]");
    printl("提示: 节点编号从1开始");
    print_gap(1);

    // a和b节点间的一条边，s是长度，v是速度
    int a,b;
    double s,v;

    for(int i=0; i<arc; i++){
        printf("边 %d: ",i+1);
        scanf("%d %d %lf %lf",&a,&b,&s,&v);

        // 验证输入
        if(a<=0||b<=0||a>vex||b>vex){
            printf("错误: 节点编号必须在1到%d之间，请重新输入\n",vex);
            i--;
            continue;
        }

        if(s<=0){
            printl("错误: 距离必须为正数，请重新输入");
            i--;
            continue;
        }

        if(v<=0){
            printl("错误: 速度必须为正数，请重新输入");
            i--;
            continue;
        }

        // 路程图
        algraph_add(*disGraph,a,b,s);
        // 将时间作为权，求时间图
        algraph_add(*timeGraph,a,b,s/v);
    }

    print_gap(1);
    printl("交通网络创建成功！按任意键继续...");
    getchar();
    getchar();
}

// 查询最短路程路线
void query_shortest_distance_path(algraph disGraph){
    if(!disGraph){
        print_title("查询最短路程路线");
        printl("交通网络尚未创建，请先创建交通网络！");
        print_gap(1);
        print("按任意键继续...");
        getchar();
        getchar();
        return;
    }

    print_title("查询最短路程路线");
    printl("请输入起点和终点 (节点编号从1开始): ");
    print("起点: ");
    int start;
    scanf("%d",&start);

    if(start<=0||start>disGraph->vexnum){
        printf("错误: 起点编号必须在1到%d之间！\n",disGraph->vexnum);
        print_gap(1);
        print("按任意键继续...");
        getchar();
        getchar();
        return;
    }

    print("终点: ");
    int end;
    scanf("%d",&end);

    if(end<=0||end>disGraph->vexnum){
        printf("错误: 终点编号必须在1到%d之间！\n",disGraph->vexnum);
        print_gap(1);
        print("按任意键继续...");
        getchar();
        getchar();
        return;
    }

    // 计算最短路程
    double minDist;
    path path=dijkstra_with_path(disGraph,start,end,&minDist);

    if(double_eq(minDist,-1)){
        printf("\n从节点 %d 到节点 %d 没有可行路径！\n",start,end);
    }
    else{
        print_path(path,"最短路程(km)",minDist);
    }

    free_path(&path);
    print_gap(1);
    print("按任意键继续...");
    getchar();
    getchar();
}

// 查询最省时路线
void query_shortest_time_path(algraph timeGraph){
    if(!timeGraph){
        print_title("查询最省时路线");
        printl("交通网络尚未创建，请先创建交通网络！");
        print_gap(1);
        print("按任意键继续...");
        getchar();
        getchar();
        return;
    }

    print_title("查询最省时路线");
    printl("请输入起点和终点 (节点编号从1开始): ");
    print("起点: ");
    int start;
    scanf("%d",&start);

    if(start<=0||start>timeGraph->vexnum){
        printf("错误: 起点编号必须在1到%d之间！\n",timeGraph->vexnum);
        print_gap(1);
        print("按任意键继续...");
        getchar();
        getchar();
        return;
    }

    print("终点: ");
    int end;
    scanf("%d",&end);

    if(end<=0||end>timeGraph->vexnum){
        printf("错误: 终点编号必须在1到%d之间！\n",timeGraph->vexnum);
        print_gap(1);
        print("按任意键继续...");
        getchar();
        getchar();
        return;
    }

    // 计算最短时间
    double minTime;
    path path=dijkstra_with_path(timeGraph,start,end,&minTime);

    if(double_eq(minTime,-1)){
        printf("\n从节点 %d 到节点 %d 没有可行路径！\n",start,end);
    }
    else{
        print_path(path,"最短时间(小时)",minTime);
    }

    free_path(&path);
    print_gap(1);
    print("按任意键继续...");
    getchar();
    getchar();
}