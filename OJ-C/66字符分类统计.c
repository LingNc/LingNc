#include<stdio.h>
int main(){
	char ch;
	int ler=0,dit=0,ohr=0;
	while(1){
		scanf("%c",&ch);
		if((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) ler+=1;
		else if(ch<=57&&ch>=48) dit+=1;
		else if(ch=='\n') break;
		else ohr+=1;
	}
	printf("letter:%d\ndigit:%d\nother:%d",ler,dit,ohr);
	return 0;
}
