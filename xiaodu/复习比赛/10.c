#include<stdio.h>


int main(){
    for(int i=1;i<=1000;i++){
        if(i%3==1&&i%5==2&&i%7==3)
            printf("%d\n",i);
    }
    return 0;
}