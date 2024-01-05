#include<stdio.h>
#include<math.h>
int is_prime(int n);
int main(){
    int T;
    scanf("%d",&T);
    for(int j=1;j<=T;j++){
        int K;
        scanf("%d",&K);
        /*
        if(is_prime(K)){
            printf("%d\n",K);
            continue;
        }
        if(K%2==0&&is_prime(K/2)){
            printf("%d\n",K/2);
            continue;
        }
        */
        int num=(int)sqrt(K);
        for(int i=2;i<=num;i++){
            //if(i%10==1||i%10==3||i%10==7||i%10==9)
                if(K%i==0)
                    if(is_prime(i)){
                        printf("%d\n",K/i);
                        break;
                    }
        }
    }
    return 0;
}
int is_prime(int n){
    if(n<=1) return 0;
    int k=sqrt(n);
    for(int i=2;i<=k;i++)
        if(n%i==0) return 0;
    return 1;
}