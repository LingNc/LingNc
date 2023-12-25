#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int num[n];
    for(int i=0;i<=n-1;i++){
        scanf("%d",&num[i]);
    }
    int t;
    scanf("%d",&t);
    int sum=0;
    for(int i=0;i<=n-1;i++){
        if(num[i]>=t) sum++;
    }
    printf("%d",sum);
    return 0;
}