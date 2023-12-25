#include<stdio.h>
int main(){
    double n,w,sum=0;
    while(scanf("%*s%lf %lf",&n,&w)!=EOF)
        sum+=n*w;
    printf("%.1lf",sum);
    return 0;
}