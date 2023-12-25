#include<stdio.h>
int have_7(int num){
	int h=1,s=num,flag=0;
	while(1){
		if(s<10) break;
		s/=10;
		h+=1;
	}
	for(int i=1;i<=h;i++){
		if(num%10==7) flag+=1;
		num/=10;
	}
	if(flag>=1) return 1;
	else return 0;
}
int main(){
	int t,N;
	scanf("%d",&t);
	for(int j=1;j<=t;j++){
		scanf("%d",&N);
		for(int i=1;i<=N;i++){
			if(i%7==0||have_7(i)==1) printf("%d ",i);
		}
		printf("\n");
	}
	return 0;
}
