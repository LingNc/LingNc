#include<stdio.h>
int main()
{
	float math,english,python,average;
	scanf("%f %f %f",&math,&english,&python);
	average=(math+english+python)/3;
	printf("%.2f",average);
	return 0;
}
