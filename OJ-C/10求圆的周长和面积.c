#include<stdio.h>
#define PI 3.14159
int main()
{
	double r,C,S;
	scanf("%lf",&r);
	C=2*PI*r;
	S=PI*r*r;
	printf("%.2lf %.2lf",C,S);
	return 0;
}
