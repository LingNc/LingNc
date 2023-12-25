#include<stdio.h>
#include<math.h>

int main(){
	int high,up,down,s=0,i=0;
	scanf("%d%d%d",&high,&up,&down);
	while(1){
		i++;
		s=(up-down)*i;
		if(s<high&&s+up>=high){
			break;//满足条件时停止循环
		}
	}
	printf("%d",i+1);//天数为i+1
	return 0;
}
