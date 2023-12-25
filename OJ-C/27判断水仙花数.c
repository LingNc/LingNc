#include<stdio.h>
#include<math.h>
int dis(int x,int n){
	int i=n-1;
	while(i>=1){
		x=(x-x%10)/10;
		i--;
	}
	x=pow(x%10,3);
	return x;
}

int main()
{
	int num;
	scanf("%d",&num);
	if(num==dis(num,3)+dis(num,2)+dis(num,1))
		printf("yes");
	else
		printf("no");
	return 0;
}
