#include<stdio.h>
int fact(int n){
    int S=1;
    for(int i=2;i<=n;i++){
        S*=i;
    }
    return S;
}
int main(){
    int m,k,C;
    scanf("%d %d",&m,&k);
    C=fact(m)/(fact(m-k)*fact(k));
    printf("%d",C);
    return 0;
}