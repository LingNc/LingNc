#include<stdio.h>
int main(){
	int sum=0;
	char ch;
	while(ch!='\n'){
		scanf("%c",&ch);
		if(ch<=57&&ch>=48) sum+=1;
	}
	printf("%d",sum);
	return 0;
}
