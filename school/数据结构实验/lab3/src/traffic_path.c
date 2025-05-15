#include "traffic_path.h"
#include "traffic_tools.h"
#include "tools.h"
#include <stdlib.h>
#include <stdio.h>

path new_path(int size){
    path path=malloc(sizeof(Path));
    path->path=malloc(sizeof(int)*size);
    path->length=0;
    return path;
}

// 释放路径
void free_path(path *path){
    if(*path){
        if((*path)->path){
            sfree((*path)->path);
        }
        sfree(path);
    }
}

// 打印路径
void print_path(path path,const char *pathType,double pathValue){
    if(!path){
        printl("无法找到路径！");
        return;
    }

    print_gap(1);
    printf("%s: %.2f\n",pathType,pathValue);
    print("路线: ");

    for(int i=0; i<path->length; i++){
        printf("%d",path->path[i]);
        if(i<path->length-1){
            printf(" ---> ");
        }
    }
    print_gap(1);
}