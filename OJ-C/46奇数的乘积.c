#include<stdio.h>
int main(){
	int n,TT=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int num;
		scanf("%d",&num);
		if(num%2==1||num%2==-1) TT*=num;
	}
	printf("%d",TT);
	return 0;
}
