#include<stdio.h>
int main()
{
	int a_1,a_n,d,S;
	scanf("%d %d %d",&a_1,&a_n,&d);
	S=(a_1+a_n)*((a_n-a_1)/d+1)/2;
	printf("%d",S);
	return 0;
}
