#include<stdio.h>
int main(){
	double cost,discount;
	scanf("%lf",&cost);
	if(cost<500) discount=1;
	else if(cost<1000) discount=0.95;
	else if(cost<3000) discount=0.9;
	else if(cost<5000) discount=0.85;
	else discount=0.8;
	printf("%.2lf",cost*discount);
	return 0;
}
