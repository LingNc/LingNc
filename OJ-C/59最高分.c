#include<stdio.h>
int main(){
	int score,max=0;
	while(1){
		scanf("%d",&score);
		if(score<0) break;
		if(score>max) max=score;
	}
	printf("%d",max);
	return 0;
}
