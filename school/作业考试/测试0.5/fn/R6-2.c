#include<stdio.h>
#include<math.h>
int prime(int n);
int main()
{
    int m,n,j,answer=0;
    scanf("%d%d",&m,&n);
    for(j=m;j<=n;j++)
    {
        if(prime(j)==1)
        {
            printf("%d ",j);
            answer=1;
        }
    }
    if(answer==1)
        printf("\n");
    else
        printf("No Answer\n");
    return 0;
}

int prime(int n){
    int sq=(int)sqrt(n);
    int flag=1;
    if(n<=2){
        flag=(n==2)?1:0;
        return flag;
    }
    for(int i=2;i<=sq;i++){
        if(n%i==0){
            flag=0;
            break;
        }
    }
    return flag;
}