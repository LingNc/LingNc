#include<stdio.h>
int main(){
	int salary=1500,sales;
	scanf("%d",&sales);
	if(sales<=10000) printf("%.2lf",salary+sales*0.05);
	else if(sales<=50000) printf("%.2lf",salary+500+(sales-10000)*0.03);
	else printf("%.2lf",salary+1700+(sales-50000)*0.02);
	return 0;
}
