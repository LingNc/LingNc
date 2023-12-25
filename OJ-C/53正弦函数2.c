#include<stdio.h>
int main(){
	double x;
	scanf("%lf",&x);
	double sum=0,flag=1,n=1,m=x;
	for(int i=1;i<=10;i++){
		sum+=flag*m/n;
		flag=-flag;
		m=m*x*x;
		n=n*(2*i)*(2*i+1);
	}
	printf("%.3lf\n",sum);
	return 0;
}

