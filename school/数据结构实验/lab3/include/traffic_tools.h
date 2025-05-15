#ifndef TRAFFIC_TOOLS_H
#define TRAFFIC_TOOLS_H

#include "graph.h"
// sleep函数
#ifdef _WIN32
#   include <windows.h>
#   define sleep(x) Sleep(x * 1000)
#else
#   include <unistd.h>
#endif

// 系统功能函数
void clears_creen();
void print_gap(int x);
void print(const char* str);
void printl(const char* str);
void print_divider();
void print_title(const char* title);
void print_main_menu();
void print_graph(algraph graph);


#endif // TRAFFIC_TOOLS_H