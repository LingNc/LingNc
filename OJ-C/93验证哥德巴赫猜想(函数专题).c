#include<stdio.h>
#include<math.h>
int prime(int n){
	int flag=0;
	if(n<=3) flag=(n==1)?0:1;
	else{
		for(int i=2;i<=(int)sqrt(n);i++){
			if(n%i==0){
				flag=0;
				break;				
			}
			else flag=1;
		}
	}
	return flag;
}

int main(){
	int M;
	scanf("%d",&M);
	for(int i=1;i<=M/2;i++){
		if(prime(i)&&prime(M-i)) printf("%d %d\n",i,M-i);
	}
	return 0;
}
