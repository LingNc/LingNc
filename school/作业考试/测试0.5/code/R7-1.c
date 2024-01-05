#include<stdio.h>
int main(){
    double n=0,sum=0;
    scanf("%lf",&n);
    for(double i=1;i<=2*n-1;i+=2)
        sum+=1/i;
    printf("%.2lf\n",sum);
    return 0;
}