#include<stdio.h>
#include<math.h>
int main()
{
	int num,len;
	scanf("%d",&num);
	len=log10(num)+1;
	printf("%d",len);
	return 0;
}
