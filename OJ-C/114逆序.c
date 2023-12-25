#include<stdio.h>
int main(){
    int n,num;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<=n-1;i++){
        scanf("%d",&num);
        a[i]=num;
    }
    for(int i=n-1;i>=0;i--){
        printf("%4d",a[i]);
    }
    return 0;
}