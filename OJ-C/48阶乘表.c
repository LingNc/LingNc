#include<stdio.h>
long long int factorial(long long int x){
	if(x==0||x==1) return 1;
	else return x*factorial(x-1);
}
int main(){
	long long int n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		printf("%-4d%-20lld\n",i,factorial(i));
	}
	return 0;
}
