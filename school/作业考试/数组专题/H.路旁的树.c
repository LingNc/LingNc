#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int tree[n];
    for(int i=0;i<=n-1;i++){
        tree[i]=1;
    }
    int k;
    scanf("%d",&k);
    while(k--){
        int start,end;
        scanf("%d %d",&start,&end);
        for(int i=start-1;i<=end-1;i++){
            tree[i]=0;
        }
    }
    int sum=0;
    for(int i=0;i<=n-1;i++){
        if(tree[i]==1) sum++;
    }
    printf("%d",sum*2);
    return 0;
}