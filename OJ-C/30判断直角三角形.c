#include<stdio.h>
int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a*a+b*b==c*c||a*a==b*b+c*c||a*a+c*c==b*b) printf("Yes");
	else printf("No");
	return 0;
}
