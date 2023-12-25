#include<stdio.h>
int main(){
	int i,j,k,n,cost,answer=0;
	scanf("%d %d",&n,&cost);
	for(i=0;i<=cost/3;i++){
        for(j=0;j<=cost/2;j++){
            k=n-i-j;
            if(i*3+j*2+k==cost&&k>=0){
                answer=1;
                printf("%d %d %d\n",i,j,k);
            }	
        }
    } 
    if(!answer){
        printf("No answer");
	}
	return 0;
}