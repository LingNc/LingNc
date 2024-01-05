#include<stdio.h>
int main(){
    int n,k;
    while(1){
        scanf("%d %d",&n,&k);
        if(n==0&&k==0) break;
        int sum=n*(1+n)/2;
        int m=n/k;
        int num=(m*(1+m)/2)*k;
        printf("%d\n",sum-num);
    }
    return 0;
}