#include<stdio.h>

int main(){
    int a=1,b=2;
    int *arr[2]={&a,&b};
    int *p=*arr;
    printf("%d",p[1]);
    return 0;
}