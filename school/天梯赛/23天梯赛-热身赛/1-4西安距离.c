#include<stdio.h>

int main(){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int L=((a>c)?a-c:c-a)+((b>d)?b-d:d-b);
    printf("%d\n",L);
    return 0;
}