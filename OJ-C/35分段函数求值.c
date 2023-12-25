#include<stdio.h>
#include<math.h>
int main(){
	int x,y;
	scanf("%d",&x);
	if(x<-2) y=7-2*x;
	else if(x>=-2&&x<3) y=5-fabs(3*x+2);
	else y=3*x+4;
	printf("%d",y);
	return 0;
}
