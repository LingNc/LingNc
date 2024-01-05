#include<stdio.h>
#include<math.h>
int prime(int n);
int main(){
    int M;
    scanf("%d",&M);
    for(int i=1;i<=M/2;i++){
        if(prime(i)&&prime(M-i))
            printf("%d %d\n",i,M-i);
    }
    return 0;
}
int prime(int n){
    int sq=sqrt(n);
    if(n<=2)
        return (n==2)?1:0;
    for(int i=2;i<=sq;i++)
        if(n%i==0) return 0;
    return 1;
}