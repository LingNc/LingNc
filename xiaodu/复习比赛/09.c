#include<stdio.h>


int main(){
    int a=1,b=1,c=0;
    printf("%d\n%d\n",1,1);
    for(int i=3;i<=20;i++){
        c=a+b;
        printf("%d\n",c);
        a=b;b=c;
    }
    return 0;
}