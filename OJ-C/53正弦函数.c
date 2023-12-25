#include <stdio.h>
#include <math.h>
long long int factorial(long long int x){
	long long int S=1;
	for(int i=1;i<=x;i++){
		S*=i;
	}
	return S;
}
double sin_a(double x){
	double y;
	y=0;
	for(int i=1; i<=10; i++){
		y+=pow(-1,i-1)*pow(x,2*i-1)/factorial(2*i-1);
	}
	return y;
}
int main(){
	double x;
	scanf("%lf",&x);
	printf("%.3lf",sin_a(x));
	return 0;
}
