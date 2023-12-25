#include<stdio.h>
#include<math.h>
int main(){
	int n,flag=0;
	scanf("%d",&n);
	if(n<=3) flag=(n==1)?0:1;
	else{
		for(int i=2;i<=(int)sqrt(n);i++){
			if(n%i==0){
			flag=0;
			break;				
			}
			else flag=1;
		}
	}
	if(flag==1) printf("Yes");
	else printf("No");
	return 0;
}
