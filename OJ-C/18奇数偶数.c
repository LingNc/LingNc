#include<stdio.h>
#include<math.h>
int main()
{
	int num;
	scanf("%d",&num);
	if((int)fabs(num)%2==1)
	{
		printf("odd");
	}
	else
	{
		printf("even");
	}
	return 0;
}
