#include<stdio.h>
int main(){
	int pbm_num,real_num=0;
	scanf("%d",&pbm_num);
	for(int i=1;i<=pbm_num;i++){
		int flag=0,n;
		n=i;
		while(n>=1){
			if(n%10!=4) n=(n-n%10)/10;
			else{
				flag=1;
				break;
			}
		}
		if(flag!=1) real_num++;
	}
	printf("%d",real_num);
	return 0;
}
