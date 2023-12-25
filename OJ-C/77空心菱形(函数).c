#include<stdio.h>
void cprint(int distant,int num){
	if(num>0){
		for(int i=1;i<=distant;i++){
			printf(" ");
		}
		for(int i=1;i<=num-1;i++){
			printf(" ");
		}
		printf("*");
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=n;i>=1;i--){
		cprint(0,i);
		cprint(0,2*(n-i));
		printf("\n");
	}
	for(int i=2;i<=n;i++){
		cprint(0,i);
		cprint(0,2*(n-i));
		printf("\n");
	}
	return 0;
}

