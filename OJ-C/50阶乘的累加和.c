#include<stdio.h>
long long int factorial(long long int x){
	if(x==0||x==1) return 1;
	else return x*factorial(x-1);
}
int main(){
	int n;
	scanf("%d",&n);
	long long int sum=0;
	for(int i=1;i<=n;i++){
		sum+=factorial(i);
	}
	printf("%lld",sum);
	return 0;
}
