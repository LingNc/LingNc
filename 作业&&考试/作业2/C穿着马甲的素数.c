#include<stdio.h>
#include<math.h>

int prime(int n);
int IsVestPrime(int n);

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i=m;i<=n;i++)
        if(IsVestPrime(i)) printf("%d ",i);
    return 0;
}
int IsVestPrime(int n){
    //int h=-1,num=n;
    /*
    while(num){
        num/=10;
        h++;
    }
    int high=1;
    while(h){
        high*=10;
        h--;
    }
    */
    int h=pow(10,(int)log10(n));
    int num_1=n%h,num_2=n/10;
    return (prime(num_1)&&prime(num_2))?1:0;
}
int prime(int n){
    int sq=sqrt(n);
    if(n<=2)
        return (n==2)?1:0;
    for(int i=2;i<=sq;i++)
        if(n%i==0) return 0;
    return 1;
}