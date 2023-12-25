#include<stdio.h>
#include<math.h>
int main(){
    int x;
    scanf("%d",&x);
    double y=(sqrt(1+8*x)-1)/2.0;
    if(y-(int)y>=pow(10,-10))
        y=(int)y+1;
    printf("%d",(int)y);
    return 0;
}