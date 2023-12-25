#include<stdio.h>
#define PI 3.14159
int main()
{
	double r,h,S;
	scanf("%lf %lf",&r,&h);
	S=2*PI*r*r+2*PI*r*h;
	printf("%.2lf",S);
	return 0;
}
