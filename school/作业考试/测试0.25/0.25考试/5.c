#include<stdio.h>
int main(){
    int n,num,S=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        S+=num;
    }
    printf("%d\n",S);
    return 0;
}