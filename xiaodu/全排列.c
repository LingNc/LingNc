#include<stdio.h>

int n,path[100],st[100];
void dfs(int u){
    if(u==n+1){
        for(int i=1;i<=n;i++) printf("%d",path[i]);
            putchar('\n');
        return;
    }
    for(int i=1;i<=n;i++){
        if(!st[i]){
            st[i]=1;
            path[u]=i;
            dfs(u+1);
            st[i]=0;
        }
    }
}
int main(){
    scanf("%d",&n);
    dfs(1);
    return 0;
}