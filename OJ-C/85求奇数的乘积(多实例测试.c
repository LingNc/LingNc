#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int s=1,num;
		for(int i=1;i<=n;i++){
			scanf("%d",&num);
			if(num%2==1||num%2==-1) s*=num;
		}
		printf("%d\n",s);
	}
	return 0;
}
