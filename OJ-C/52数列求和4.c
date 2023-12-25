#include<stdio.h>
int main(){
	int n,a,s,sum=0;
	scanf("%d %d",&n,&a);
	s=a;
	for(int i=1;i<=n;i++){
		sum+=s;
		s=s*10+a;
	}
	printf("%d",sum);
	return 0;
}
