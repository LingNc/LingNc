#include<stdio.h>
#include<math.h>
double funF(double x){
    return fabs(x-3)+fabs(x+1);
}
double funG(double x){
    return x*x-3*x;
}
int main(){
    double x;
    scanf("%lf",&x);
    printf("%.2lf",funF(funG(x)));
    return 0;
}