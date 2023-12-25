#include<stdio.h>
int main(){
	char ID;
	int n,year,month,day;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		year=0;month=0;day=0;
		for(int j=1;j<=18;j++){
			scanf(" %c",&ID);
			if(j>=7&&j<=14){
				switch (j) {
				case 7:year+=(ID-'0')*1000;break;
				case 8:year+=(ID-'0')*100;break;
				case 9:year+=(ID-'0')*10;break;
				case 10:year+=(ID-'0');break;
				case 11:month+=(ID-'0')*10;break;
				case 12:month+=(ID-'0');break;
				case 13:day+=(ID-'0')*10;break;
				case 14:day+=(ID-'0');break;
				}
			}
		}
		printf("%04d-%02d-%02d\n",year,month,day);
	}
	return 0;
}
