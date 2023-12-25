#include<stdio.h>
int main(){
	char ch='0';
	int a=0;
	while(ch!='\n'){
		a=a*2+(ch-'0');
		scanf("%c",&ch);
	}
	printf("%d",a);
	return 0;
}
