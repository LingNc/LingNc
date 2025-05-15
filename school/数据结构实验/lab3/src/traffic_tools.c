#include "traffic_tools.h"
#include <stdio.h>
#include <stdlib.h>

// 清屏函数双系统
void clears_creen(){
#   ifdef _WIN32
    system("cls");
#   else
    system("clear");
#   endif
}

// 换行函数双系统
void print_gap(int x){
#   ifdef _WIN32
    for(int i=0; i<x; i++){
        printf("\r\n");
    }
#   else
    for(int i=0; i<x; i++){
        printf("\n");
    }
#   endif
}

// 输出函数
void print(const char *str){
    printf("%s",str);
}

// 换行输出
void printl(const char *str){
    printf("%s",str);
    print_gap(1);
}

// 打印分隔线
void print_divider(){
    print_gap(1);
    for(int i=0; i<60; i++){
        print("=");
    }
    print_gap(2);
}

// 打印标题
void print_title(const char *title){
    clears_creen();
    print_gap(1);
    print_divider();
    printf("\t\t%s\n",title);
    print_divider();
}

// 打印主菜单
void print_main_menu(){
    print_title("城市交通咨询模拟系统");
    printl("1. 创建交通网络");
    printl("2. 查询最短路程路线");
    printl("3. 查询最省时路线");
    printl("4. 显示交通网络");
    printl("5. 退出系统");
    print_gap(1);
    print("请选择操作 [1-5]: ");
}

// 打印图信息
void print_graph(algraph graph){
    if(!graph){
        print_title("显示交通网络");
        printl("交通网络尚未创建！");
        print_gap(1);
        print("按任意键继续...");
        getchar();
        getchar();
        return;
    }

    print_title("显示交通网络");
    printf("节点数量: %d\n",graph->vexnum);
    printf("边数量: %d\n",graph->arcnum);
    print_gap(1);

    printl("交通网络连接信息:");
    for(int i=1; i<=graph->vexnum; i++){
        printf("节点 %d 连接到: ",i);
        sqlist adjacentNodes=algraph_visit(graph,i);
        int size=sqlist_size(adjacentNodes);

        if(size==0){
            printl("无连接");
            continue;
        }

        for(int j=0; j<size; j++){
            arcnode arc=sqlist_at(adjacentNodes,j);
            printf("%d(权值:%.2f) ",arc->adjvex,arc->weight);
        }
        print_gap(1);
    }

    print_gap(1);
    print("按任意键继续...");
    getchar();
    getchar();
}