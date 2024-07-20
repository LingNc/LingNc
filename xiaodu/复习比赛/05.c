#include<stdio.h>

int main(){
    int a=300,b=400;
    for(int i=a;i<=b;i++){
        if(!(i%5==0&&i%7==0))
            printf("%d\n",i);
    }
    return 0;
}