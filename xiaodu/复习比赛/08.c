#include<stdio.h>


int main(){
    int i=1;
    int sum=0;
    do{
        sum+=i;
        i++;
    }while(i<=50);
    printf("%d",sum);
    return 0;
}