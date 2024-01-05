#include<time.h>
#include<stdio.h>
static clock_t start_time;
//计算用时开始
clock_t start(){
    start_time=clock();
    return start_time;
}
//计算用时结束
/*
double end(clock_t start){
    clock_t end=clock();
    double Times=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nThis time: %.3lfms",Times*1000);
    return Times;
}
*/
//计算用时结束
double end(){
    clock_t end=clock();
    double Times=(double)(end-start_time)/CLOCKS_PER_SEC;
    printf("\nThis time: %.3lfms\n",Times*1000);
    return Times;
}