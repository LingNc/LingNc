#include<stdio.h>
#inc
int fun(int x);
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i=0;i<=1000;i++){
        if(fun(m+i)&&fun(n+i)){
            printf("%d ",(m+i)*(n+i));
            if((m+i)>(n+i)) printf("%d ",m+i);
            else printf("%d",n+i);
            printf("\n");
        }
    }
    return 0;
}
int fun(int x){
    if(x==2||x==3)
        return 1;
    if(x==1)
        return 0;
    int q=(int)sqrt(x);

    for(int i=2; i<=q; i++){
        if(x%i==0)
            return 0;
    }

    return 1;
}