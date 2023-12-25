#include<stdio.h>
int main(){
	int x,y,z,n,flag=0;
	scanf("%d",&n);
	for(x=1;x<=9;x++){
		for(y=1;y<=9;y++){
			for(z=0;z<=9;z++){
				if(100*x+110*y+12*z==n){
					printf("%4d%4d%4d",x,y,z);
					flag=1;
				}
				
			}
		}
	}
	if(flag==0) printf("No Answer");
	return 0;
}