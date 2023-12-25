#include <stdio.h>
#include <math.h>
int main(){
	double s1,s2,result,err=1;
	char op;
	scanf("%lf %c %lf",&s1,&op,&s2);
	switch(op){
		case '+':result=s1+s2;break;
		case '-':result=s1-s2;break;
		case '*':result=s1*s2;break;
		case '/':
		if(s2<pow(10,-10)) err=0;
		else result=s1/s2;
		break;
	default:err=0;}
	if(err==1) printf("%.2lf",result);
	else printf("Wrong input!");
	return 0;
	}

