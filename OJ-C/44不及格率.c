#include<stdio.h>
int main()
{
	double n,unpass=0;
	scanf("%lf",&n);
	for(int i=1;i<=n;i++){
		double grade;
		scanf("%lf",&grade);
		if(grade<60) unpass+=1;
	}
	printf("%.2lf",unpass/n);
	return 0;
}
