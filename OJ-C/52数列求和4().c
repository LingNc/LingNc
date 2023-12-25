#include<stdio.h>
#include<math.h>
int a;
int aaa(int n,int x){
	if(n==0) return 0;
	else return x*pow(10,n-1)+aaa(n-1,x);
}
int sum(int n){
	if(n==0) return 0;
	else return aaa(n,a)+sum(n-1);
}
int main(){
	int n;
	scanf("%d %d",&n,&a);
	printf("%d",sum(n));
	return 0;
}
