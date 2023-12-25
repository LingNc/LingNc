#include<stdio.h>
int main(){
	int year,flag;
	flag=0;
	scanf("%d",&year);
	if(year%4==0||year%400==0){
		if(year%100==0&&year%400!=0) flag+=1;
	}
	else flag+=1;
	if(flag==1) printf("No");
	else printf("Yes");
	return 0;
}
