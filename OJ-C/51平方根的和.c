#include<stdio.h>
#include<math.h>
double item;
int main(){
	double n;
	scanf("%lf %lf",&item,&n);
	double sqrt_list(double x){
		if(x==1) return item;
		else return sqrt(sqrt_list(x-1));
	}
	double sum(double x){
		if(x==0) return 0;
		else return sqrt_list(x)+sum(x-1);
	}
	printf("%.2lf",sum(n));
	return 0;
}
