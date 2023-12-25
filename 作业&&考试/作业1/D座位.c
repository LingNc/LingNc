#include<stdio.h>
int main(){
    int m,L,S,x,y;
    scanf("%d %d %d %d %d",&m,&L,&S,&x,&y);
    long long int sum=0;
    sum=m*(L*x+S*y);
    printf("%lld",sum);
    return 0;
}