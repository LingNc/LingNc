#include<stdio.h>
int main(){
    int n,i,x,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&x);
        for(j=1;j<=x;j++){
            if(j%7==0||j%10==7||j/10%10==7||j/100%10==7||j/1000%10==7){
                printf("%d ",j);

            }
        }
        printf("\n");
    }
    return 0;
}