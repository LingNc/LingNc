#include<stdio.h>
int main(){
    int n,m,inverse(int);
    scanf("%d",&n);
    printf("%d ",n);
    while(m=inverse(n),m!=n){
        n=m+n;
        printf("%d ",n);
    }
    return 0;
}

int inverse(int number){
    int S=0;
    while(number>0){
        S=(S+number%10)*10;
        number/=10;
    }
    return S/10;
}
