#include<stdio.h>
#include<math.h>
double CancelFee(double price){
    double cost=0.05*price,cost_int,cost_dit;
    cost_int=(int)cost;
    cost_dit=cost-cost_int;
    if(cost_dit<0.25) cost_dit=0;
    else if(cost_dit<0.75) cost_dit=0.5;
    else cost_dit=1;
    return cost_int+cost_dit;
}
int main(){
    double x;
    scanf("%lf",&x);
    printf("%.2lf",CancelFee(x));
    return 0;
}