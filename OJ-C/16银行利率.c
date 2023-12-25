#include<stdio.h>
int main()
{
	const double rate=0.0225;
	double n,capital,interest;
	scanf("%lf %lf",&n,&capital);
	for(int i=1;i<=n;i++)
	{
		interest=capital*rate;
		capital=capital+interest;
	}
	printf("%.6lf",capital);
	return 0;
}
