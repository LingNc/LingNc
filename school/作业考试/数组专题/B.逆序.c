#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int i=n,num[n];
    while(i--){
        scanf("%d",&num[i]);
    }
    for(int i=0;i<=n-1;i++){
        printf("%4d",num[i]);
    }
    return 0;
}