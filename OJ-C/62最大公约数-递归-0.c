#include<stdio.h>

int gcd(int m,int n);
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    printf("%d",gcd(m,n));
    return 0;
}
int gcd(int m,int n){
	if(m==n) return m;
	return (m>n)?gcd(m-n,n):gcd(n-m,m);
}