#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	printf("%-9d%-9d%-9d\n",a,(int)pow(a,2),(int)pow(a,3));
	printf("%-9d%-9d%-9d\n",b,(int)pow(b,2),(int)pow(b,3));
	printf("%-9d%-9d%-9d",c,(int)pow(c,2),(int)pow(c,3));
	return 0;
}
