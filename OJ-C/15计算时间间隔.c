#include<stdio.h>
int main()
{
	int h1,h2,m1,m2,s1,s2,gap;
	scanf("%d:%d:%d",&h1,&m1,&s1);
	scanf("%d:%d:%d",&h2,&m2,&s2);
	gap=3600*(h2-h1)+60*(m2-m1)+s2-s1;
	printf("%d",gap);
	return 0;
}
