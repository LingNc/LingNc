#include<stdio.h>
//把时分秒转换成秒并返回, 三个参数分别为用于表示一个时间点的时、分、秒
int HmsToS(int h, int m, int s){
    return 3600 * h + 60 * m + s;
}
//将时间段转换为对应的“小时:分钟:秒” 格式输出 ,形参s表示一个时间段的长度，单位是秒
void PrintTime(int s){
    int h, m, s_0;
    h = s / 3600;
    m = (s%3600)/60;
    s_0 = s-h*3600-m*60;
    printf("%02d:%02d:%02d\n", h, m, s_0);
}
int main(){
    while(1){
        int h1,h2,m1,m2,s1,s2,time;
        scanf("%d:%d:%d",&h1,&m1,&s1);
        scanf("%d:%d:%d",&h2,&m2,&s2);
        PrintTime(HmsToS(h2,m2,s2)-HmsToS(h1,m1,s1));
    }
}