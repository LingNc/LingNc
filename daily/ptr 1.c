#include<stdio.h>

int main(){
    int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    int (*p1)[4]=a;
    printf("%d %d %p %p",p1,p1+1);
    return 0;
}