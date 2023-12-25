#include<stdio.h>
int main(){
	char x,y,z,t;
	while(scanf("%c%c%c",&x,&y,&z)!=EOF){
		if(y>x){t=y;y=x;x=t;}
		if(z>x){t=z;z=x;x=t;}
		if(z>y){t=z;z=y;y=t;}
		printf("%c %c %c\n",z,y,x);
	}
	return 0;
}
