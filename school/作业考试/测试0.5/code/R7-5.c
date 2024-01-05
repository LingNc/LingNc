#include<stdio.h>
int main(){
    int n,flag[101]={0};
    scanf("%d",&n);
    for(int i=0;i<=n-1;i++){
        int x;
        scanf("%d",&x);
        flag[x]++;
    }
    int max;
    for(int i=1;i<=100;i++){
        if(flag[i]!=0)
            max=i;
    }
    printf("%d %d",max,flag[max]);
    return 0;
}