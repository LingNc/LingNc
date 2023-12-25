#include<stdio.h>
int main()
{
	char c;
	scanf("%c",&c);
	if(c>=97&&c<=122){
		c-=32;
	}
	printf("%c",c);
	return 0;
}
