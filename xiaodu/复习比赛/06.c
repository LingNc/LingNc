#include<stdio.h>

int main(){
    double r=0.07;
    double p=1;
    for(int i=1;i<=10;i++){
        p=p*(1+r);
    }
    printf("%.2lf",(p-1)*100);
    return 0;
}