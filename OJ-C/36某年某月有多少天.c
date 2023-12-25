#include<stdio.h>
int run(int year){
	int flag;
	flag=0;
	if(year%4==0||year%400==0){
		if(year%100==0&&year%400!=0) flag+=1;}
	else flag+=1;
	if(flag==1) return 0;
	else return 1;}

int main(){
	int yaer,month;
	scanf("%d %d",&yaer,&month);	
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12) 
		month=31;
	else{
		if(month!=2)
			month=30;
		else 
			month = (run(yaer))?29:28;
	}
	printf("%d\n",month);
	return 0;
}
