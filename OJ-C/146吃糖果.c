#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int m;
        scanf("%d",&m);
        int candy[m];
        for(int j=0;j<=m-1;j++)
            scanf("%d",&candy[j]);
        int max=-1,k;
        for(int i=0;i<=m-1;i++){
            if(candy[i]>=max){
                max=candy[i];
                k=i;
            }
        }
        int sum=0;
        for(int i=0;i<=m-1;i++)
            sum+=candy[i];
        sum-=candy[k];
        if(sum>=max-1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
