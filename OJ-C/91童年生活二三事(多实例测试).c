#include<stdio.h>
int C(int m,int n){
	int result=1;
	if(m!=0&&n!=0){
		int i=m+1,j=2;
		while(i<=n){
			result*=i;
			if(j<=n-m&&result%j==0){
				result/=j;
				j++;
			}
			i++;
		}
	}
	return result;
}

int main(){
	int N;
	scanf("%d",&N);
	while(N>=1){
		int result=0;
		if(N==0) break;
		else if(N==1) result=1; 
		else{
			for(int i=0;i<=N;i++){
				if(i>N-i) break;
				result+=C(i,N-i);
			}
		}
		printf("%d\n",result);
		N--;
	}
	return 0;
}
