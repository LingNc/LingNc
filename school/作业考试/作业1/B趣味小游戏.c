#include<stdio.h>
int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        for(int i=0;i<=99;i++)
            if((100*a+i)%b==0)
                printf("%02d ",i);
        printf("\n");
    }
    return 0;
}