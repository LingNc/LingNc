#include<stdio.h>
int thrend(int num_1,int num_2){
	int result,restrnd;
	result=num_1*num_2;
	restrnd=result%1000;
	return restrnd;
}
int main(){
	int n,result;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int A,B;
		scanf("%d %d",&A,&B);
		result=A;
		for(int j=2;j<=B;j++){
			result=thrend(result,A);
		}
		printf("%d\n",result);
	}
	return 0;
}
