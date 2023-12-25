#include<stdio.h>
int main(){
	int n,x=1;
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		x=2*(x+1);
	}
	printf("%d",x);
 	return 0;
}
