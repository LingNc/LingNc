#include<stdio.h>
int main()
{
	int x,y,z,t;
	scanf("%d %d %d",&x,&y,&z);
	if(y>x){t=x;x=y;y=t;}
	if(z>x){t=x;x=z;z=t;}
	if(z>y){t=z;z=y;y=t;}
	printf("%d %d %d",x,y,z);
	return 0;
}
