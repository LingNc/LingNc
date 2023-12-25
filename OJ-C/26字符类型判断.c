#include<stdio.h>
int main()
{
	char c;
	scanf("%c",&c);
	if(65<=c&&c<=90)
		printf("upper");
	else if(97<=c&&c<=122)
		printf("lower");
	else if(48<=c&&c<=57)
		printf("digit");
	else
		printf("other");
	return 0;
}
