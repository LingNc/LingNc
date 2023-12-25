#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,p,S;
	scanf("%lf %lf %lf",&a,&b,&c);
	p=(a+b+c)/2;
	S=sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%0.2lf",S);
	return 0;
}
