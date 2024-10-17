#include<stdio.h>
int main(){
    int a,b,x,min;
    scanf("%d %d",&a,&b);
    if(a>=b){
        x=a-b,min=b;
    }
    else{
        x=b-a,min=a;
    }
    while(x>=1){
        if(a-x==0&&b-x==0){
            printf("%d",x);
            break;
        }
        if(x>min){
            x=x-min;
        }
        else{
            x=min-x;
        }
    }
}