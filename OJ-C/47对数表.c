#include<stdio.h>
#include<math.h>
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	for(int i=0;i<=n-m;i++){
		printf("%4d%8.4lf\n",m+i,log((double)(m+i)));
	}
	return 0;
}
