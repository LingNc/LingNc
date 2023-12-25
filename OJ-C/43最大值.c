#include<stdio.h>
int max(int n){
	int x;
	scanf("%d",&x);
	if(n==1){
		return x;
	}
	else{
		int y=max(n-1);
		if(y>x) return y;
		else return x;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d",max(n));
	return 0;
}

