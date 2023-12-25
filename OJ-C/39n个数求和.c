#include<stdio.h>
int main()
{
	int n,S;
	scanf("%d",&n);
	S=0;
	for(int i=1;i<=n;i++){
		int num;
		scanf("%d",&num);
		S+=num;
	}
	printf("%d",S);
	return 0;
}
