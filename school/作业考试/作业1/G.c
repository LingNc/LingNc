#include <stdio.h>
#include <math.h>

int fun(int x);

int main(void){
    int T,n;
    scanf("%d",&T);

    for(int j=0; j<T; j++){
        scanf("%d",&n);
        if(fun(n))
            printf("%d\n",n);
        else{
            int q=(int)sqrt(n);

            for(int i=2; i<=q; i++){
                if(n%i==0){
                    if(fun(i)&&fun(n/i)){
                        printf("%d\n",n/i);
                        break;
                    }
                }
            }
        }
    }
}

int fun(int n){
    if(n==2) return 1;
    if(n<=1) return 0;
    int k=(int)sqrt(n);
    for(int i=2;i<=k;i++)
        if(n%i==0) return 0;
    return 1;
}