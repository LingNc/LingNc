#include<stdio.h>
int main()
{
	int ticket;
	scanf("%d",&ticket);
	if(ticket<30)
	{
		printf("%d",50*ticket);
	}
	else
	{
		printf("%d",48*ticket);
	}
	return 0;
}
