#include<stdio.h>
int main(){
	double n,m=1,x=1,S=0;
	scanf("%lf",&n);
	for(int i=1;i<=n;i++){
		S+=x*i;
		if(S>=n){
			m=i-1;
			break;
		} 
		x*=i;
	}
	printf("m<=%.0lf",m);
	return 0;
}
