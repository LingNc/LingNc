#include<stdio.h>
int main(){
	char x,y,z,t;
	scanf("%c %c %c",&x,&y,&z);
	if(y>x){ t=x;x=y;y=t; }
	if(z>x){ t=x;x=z;z=t; }
	if(z>y){ t=z;z=y;y=t; }
	printf("%c",x);
	return 0;
}
