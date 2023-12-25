#include<stdio.h>
int main()
{
	int n,net_num=0,pos_num=0,zero=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int num;
		scanf("%d",&num);
		if(num==0) zero+=1;
		else if(num<0) net_num+=1;
		else pos_num+=1;
	}
	printf("%d %d %d",net_num,zero,pos_num);
	return 0;
}
