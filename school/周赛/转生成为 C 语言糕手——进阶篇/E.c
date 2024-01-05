#include<stdio.h>
int main(){
    int n,u,v;
    scanf("%d",&n);
    int in[n],out[n];
    for(int i=0;i<=n-1;i++)
        in[i]=out[i]=0;
    for(int i=1;i<=n-1;i++){
        scanf("%d %d",&u,&v);
        in[u-1]++;
        out[v-1]++;
    }
    int flag;
    for(int i=0;i<=n-1;i++)
        if(in[i]==0) flag=i+1;
    printf("%d",flag);
    return 0;
}