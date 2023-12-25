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
	int m,n;
	scanf("%d %d",&m,&n);
	for(int i=m;i<=n;i++){
		if(prime(i)) printf("%d ",i);
	}
	return 0;
}
