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