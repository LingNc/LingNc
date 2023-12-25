#include<stdio.h>
#include<math.h>
int main()
{
	double n,S;
	S=0;
	scanf("%lf",&n);
	for(int i=1;i<=2*n-1;i+=2){
		int x;
		x=(i%4==3)?-1:1;
		S+=x*(((double)i-1)/2+1)/(double)i;
	}
	printf("%.3lf",S);
	return 0;
}
