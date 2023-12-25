#include<stdio.h>
int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    long long int num[N+1];
    for(int i=0;i<=N-1;i++){
        num[i]=0;
    }
    int start,end,n;
    while(M--){
        scanf("%d %d %d",&start,&end,&n);
        for(int i=start;i<=end;i++){
            num[i]+=n;
        }
    }
    for(int i=1;i<=N;i++){
        printf("%d ",num[i]);
    }
    printf("\n");
    return 0;
}