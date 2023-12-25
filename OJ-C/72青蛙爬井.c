#include<stdio.h>
int main(){
	int high,up,down,i=0;
	scanf("%d %d %d",&high,&up,&down);
	while(1){
		i+=1;
		high-=up;
		if(high<=0) break;
		high+=down;
	}
	printf("%d",i);
	return 0;
}
