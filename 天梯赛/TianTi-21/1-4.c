#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n%2==1||n==0)
        printf("NO");
    else{
        printf("YES\n");
        for(int i=1;i<=n/2;i++){
            printf("AK");
        }
    }
    return 0;
}