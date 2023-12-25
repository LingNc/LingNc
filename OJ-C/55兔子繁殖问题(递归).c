#include<stdio.h>
int Fibonacci(int n){
	if(n<=2) return 1;
	else return Fibonacci(n-1)+Fibonacci(n-2);
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d",Fibonacci(n));
	return 0;
}
