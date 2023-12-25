#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int S[n],a[n],num;
    for(int i=0;i<=n-1;i++){
        a[i]=0;
        S[i]=0;
    }
    for(int i=0;i<=n-1;i++){
        scanf("%d",&num);
        a[i]=num;
    }
    for(int i=0;i<=n-1;i++){
        if(i==0) S[i]=a[i];
        else S[i]+=S[i-1]+a[i];
    }
    for(int i=0;i<=n-1;i++)
        printf("%d\n",S[i]);
    return 0;
}