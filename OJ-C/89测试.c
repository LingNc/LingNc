#include<stdio.h>

int factorial_high(int n){
	long long int result[350];
	int high=0;
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
		else{
			int res=result[i],n=0;
			while(1){
				if(res>0){
					res/=10;
					n++;
				}
				else break;
			}
			int h=1;
			for(int i=1;i<=n-1;i++) h*=10;
			high=result[i]/h;
			break;
		}
	}
	return high;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		printf("%d ",factorial_high(i));
	}
}
