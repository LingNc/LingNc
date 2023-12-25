#include<stdio.h>
int main(){
	int n;
	char phone[12],sh_pho[6];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%12s",phone);
		sscanf(phone,"%*6s%5s",sh_pho);
		printf("6%s\n",sh_pho);
	}
	return 0;
}
