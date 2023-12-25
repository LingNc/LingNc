#include<stdio.h>
int main(){
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    int in[n],out[n];
    for(int i=0;i<=n-1;i++)
        in[i]=out[i]=0;
    for(int i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        in[u-1]++;
        out[v-1]++;}
    for(int i=0;i<=n-1;i++) 
        printf("%d %d\n",in[i],out[i]);
    return 0;
}