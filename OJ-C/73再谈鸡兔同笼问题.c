#include<stdio.h>
int main(){
	int m,n,ckn,rbt;
	scanf("%d %d",&m,&n);
	if(n%2!=0) printf("No Answer");
	else{
		ckn=2*m-n/2;
		rbt=m-ckn;
		if(ckn<0||rbt<0) printf("No Answer");
		else printf("%d %d",ckn,rbt);
	}
	return 0;
}
