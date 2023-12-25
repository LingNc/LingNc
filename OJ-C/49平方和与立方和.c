#include<stdio.h>
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	long long int dab_num=0,slg_num=0;
	for(int i=m;i<=n;i++){
		if(i%2==1) slg_num+=i*i*i;
		else dab_num+=i*i;
	}
	printf("%lld %lld",dab_num,slg_num);
	return 0;
}
