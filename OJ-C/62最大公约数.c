#include<stdio.h>
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	while(1){
		if(m>n) m=m-n;
		else if(m<n) n=n-m;
		else break;
	}
	printf("%d",n);
	return 0;
}

