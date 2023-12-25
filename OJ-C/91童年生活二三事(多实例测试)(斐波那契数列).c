#include<stdio.h>
int Fibonacci(int n){
	int a=1,b=1,c;
	if(n==1||n==2) return 1;
	for(int i=3;i<=n;i++){
		c=a+b;a=b;b=c;
	}
	return c;
}
int main(){
	int N;
	while(1){
		scanf("%d",&N);
		if(N==0) break;
		printf("%d\n",Fibonacci(N+1));
	}
	return 0;
}
