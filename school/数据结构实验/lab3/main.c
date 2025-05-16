#include <stdio.h>
#include "traffic_ui.h"
#include "traffic_tools.h"

// 运行交通咨询系统
void run_traffic_system(){
    // 初始化接口
    init_pair_inter();

    algraph disGraph=NULL;  // 路程图
    algraph timeGraph=NULL; // 时间图

    int choice=0;

    while(1){
        print_main_menu();
        scanf("%d",&choice);

        switch(choice){
        case 1:
            create_traffic_network(&disGraph,&timeGraph);
            break;
        case 2:
            query_shortest_distance_path(disGraph);
            break;
        case 3:
            query_shortest_time_path(timeGraph);
            break;
        case 4:
            print_graph(disGraph);
            break;
        case 5:
            // 释放资源
            if(disGraph) free_algraph(&disGraph);
            if(timeGraph) free_algraph(&timeGraph);
            free_pair_inter();
            print_title("感谢使用城市交通咨询模拟系统");
            print("程序已退出");
            print_gap(2);
            return;
        default:
            printl("无效的选择，请重新输入！");
            sleep(1);
            break;
        }
    }
}

int main(){
    // 运行交通咨询系统
    run_traffic_system();
    return 0;
}

/*
4
5
1 2 2 1
1 3 5 2
2 3 1 1
2 4 3 1
3 4 2 2

9  // 顶点数
11  // 边数
1 2 12 40  // v1->v2, 距离12km, 速度40km/h
1 3 8 50   // v1->v3, 距离8km, 速度50km/h
1 4 6 60   // v1->v4, 距离6km, 速度60km/h
2 5 5 20   // v2->v5, 距离5km, 速度20km/h
3 5 8 25   // v3->v5, 距离8km, 速度25km/h
4 6 7 55   // v4->v6, 距离7km, 速度55km/h
5 7 5 20   // v5->v7, 距离5km, 速度20km/h
5 8 6 20   // v5->v8, 距离6km, 速度20km/h
6 8 10 40  // v6->v8, 距离10km, 速度40km/h
7 9 6 30   // v7->v9, 距离6km, 速度30km/h
8 9 8 25   // v8->v9, 距离8km, 速度25km/h

9
11
1 2 12 40
1 3 8 50
1 4 6 60
2 5 5 20
3 5 8 25
4 6 7 55
5 7 5 20
5 8 6 20
6 8 10 40
7 9 6 30
8 9 8 25
*/