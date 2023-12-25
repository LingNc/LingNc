#include<stdio.h>
int main(){
	int m,n,flag=0,luck;
	scanf("%d %d",&m,&n);
	for(int i=n;i>=m;i--){
		if(i%7==0&&i%4!=0){
			luck=i;
			flag+=1;
			break;
		} 
	}
	if(flag==0){
		printf("no");
	}
	else printf("%d",luck);
	return 0;
}
