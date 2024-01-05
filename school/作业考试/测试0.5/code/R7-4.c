#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int num[100]={0};
    for(int i=0;i<=n-1;i++)
        scanf("%d",&num[i]);
    int x,y;
    scanf("%d %d",&x,&y);
    int sum=0;
    for(int i=x;i<=y;i++)
        sum+=num[i];
    if(x>n-1) sum=0;
    printf("%d",sum);
    return 0;
}