#include<stdio.h>
int main(){
	int boy=0,girl,cost,n,flag=0;
	scanf("%d %d",&n,&cost);
	while(1){
		girl=cost-n-2*boy;
		if(girl>=0&&n-(boy+girl)>=0){
			printf("%d %d %d\n",boy,girl,n-(boy+girl));
			boy+=1;
			flag+=1;
			continue;
		}
		else if(flag==0&&boy==n){
			printf("No answer");
			break;
		}
		else if(boy<n){
			boy+=1;
			continue;
		}
		else break;
	}
	return 0;
}
