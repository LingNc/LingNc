#ifndef TRAFFIC_UI_H
#define TRAFFIC_UI_H

#include "graph.h"
#include "traffic_path.h"

// 算法和交互功能
// 初始化接口
void init_pair_inter();
// 释放接口
void free_pair_inter();
// Dijkstra算法（返回路径）
path dijkstra_with_path(algraph graph,int start,int end,double *minDist);
// 创建交通网络
void create_traffic_network(algraph *disGraph,algraph *timeGraph);
// 查询最短路程路线
void query_shortest_distance_path(algraph disGraph);
// 查询最省时路线
void query_shortest_time_path(algraph timeGraph);

#endif