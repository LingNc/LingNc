#include<stdio.h>
int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    int num[N+1];
    for(int i=0;i<=N;i++){
        num[i]=0;
    }
    while(M--){
        int start,end,n;
        scanf("%d %d %d",&start,&end,&n);
        num[start]+=n;
        num[end+1]-=n;
    }
    for(int i=1;i<=N;i++){
        num[i]+=num[i-1];
        printf("%d ",num[i]);
    }
    return 0;
}