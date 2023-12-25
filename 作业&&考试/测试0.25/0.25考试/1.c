#include<stdio.h>
#define PI 3.14159
int main(){
    double r,C,S;
    scanf("%lf",&r);
    S=PI*r*r;
    C=2*PI*r;
    printf("%.2lf %.2lf",C,S);
    return 0;
}