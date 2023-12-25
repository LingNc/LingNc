#include<stdio.h>
#include<math.h>
int max(int x,int y){
	if(fabs(x)>fabs(y)) return x;
	else return y;
}
int main()
{
	int a,b,c,big;
	scanf("%d %d %d",&a,&b,&c);
	big=max(c,b);
	big=max(big,a);
	printf("%d",big);
	return 0;
}
