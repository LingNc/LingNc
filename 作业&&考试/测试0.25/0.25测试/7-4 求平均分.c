#include<stdio.h>
int main(){
    double a,b,c;
    scanf("%lf %lf %lf",&a,&b,&c);
    printf("%.2lf",(a+b+c)/3);
    return 0;
}