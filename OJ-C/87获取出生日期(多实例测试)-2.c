#include<stdio.h>
int main(){
	int n;
	char ID[19],year[5],month[3],day[3];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%18s",ID);
		sscanf(ID,"%*6s%4s%2s%2s",year,month,day);
		printf("%s-%s-%s\n",year,month,day);
	}
	return 0;
}
