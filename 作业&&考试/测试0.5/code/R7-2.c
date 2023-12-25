#include<stdio.h>
long long int fact(int x);
int main(){
    int n=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        printf("%-4d%-20lld\n",i,fact(i));
    return 0;
}
long long int fact(int x){
    long long int sum=1;
    for(int i=1;i<=x;i++)
        sum*=i;
    return sum;
}