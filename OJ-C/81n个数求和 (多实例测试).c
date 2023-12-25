#include<stdio.h>
int main()
{
	int T,n,S;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d",&n);
		S=0;
		for(int i=1;i<=n;i++){
			int num;
			scanf("%d",&num);
			S+=num;
		}
		printf("%d\n",S);
	}
	return 0;
}
