#include<stdio.h>
int main(){
	char ch;
	do{
		scanf("%c",&ch);
		if('A'<=ch&&ch<='Z') ch+=32;
		if('a'<=ch&&ch<='y') ch++;
		else if(ch=='z') ch='a';
		else if(ch=='@') break;
		else ch=ch;
		printf("%c",ch);
	}while(1);
	return 0;
}
