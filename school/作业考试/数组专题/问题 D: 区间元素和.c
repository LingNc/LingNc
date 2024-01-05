#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int num[n];
    for(int i=0;i<=n-1;i++){
        scanf("%d",&num[i]);
    }
    int left,right;
    scanf("%d %d",&left,&right);
    int sum=0;
    for(int i=left;i<=right;i++){
        if(i<=n-1&&i>=0)
            sum+=num[i];
    }
    printf("%d",sum);
    return 0;
}