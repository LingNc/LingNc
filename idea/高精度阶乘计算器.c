#include<stdio.h>

int main(){
	long long int result[350];
	int n;
	scanf("%d",&n);
	for(int i=1;i<=350;i++) result[i-1]=0;//初始化数组
	result[349]=1;
	for(int i=1;i<=n;i++){
		long long int plus=0;
		for(int j=349;j>=0;j--){
			result[j]*=i;
			result[j]+=plus;
			plus=0;
			if(result[j]>99999999){
				plus=result[j]/100000000;
				result[j]%=100000000;
			}
		}
	}
	for(int i=0;i<=349;i++){
		if(result[i]==0) continue;
		else printf("%lld",result[i]);
	}
	return 0;
}
