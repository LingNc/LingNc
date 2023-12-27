#include<stdio.h>
int main()
{
	int n,i;
	double y;
	scanf("%d",&n);
	y=1.0;
	for(i=1;i<=n;i++){
		y=y*i;
		while(y>=10){
			y=y/10;
		}
	}
	printf("%d",(int)y);
	return 0;
}
