#include<stdio.h>
#include<math.h>
int prime(int n);
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i=m;i<=n;i++)
        if(prime(i)) printf("%d ",i);
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