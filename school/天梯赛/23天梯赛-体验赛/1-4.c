#include<stdio.h>
int main(){
	int n;
    scanf("%d",&n);
    while(n--){
        int sum=0;
        for(int i=1;i<=5;i++){
            int b=0;
            scanf("%d",&b);
            sum+=(b==0)?0:1;
        }
        printf("%d\n",sum);
    }
    return 0;
}