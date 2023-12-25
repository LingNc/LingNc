#include<stdio.h>
int main(){
	int M,k;
	scanf("%d %d",&M,&k);
	for(int i=1;i<=M;i++){
		if(i%k==0) M++;
	}
	printf("%d",M);
	return 0;
}