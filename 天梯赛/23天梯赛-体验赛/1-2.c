#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int x=0;
    for(int i=2;i<n;i++){
        if(n%i==0) x=i;
    }
    printf("%d\n",x);
    return 0;
}