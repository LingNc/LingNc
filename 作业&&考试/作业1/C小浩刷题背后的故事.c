#include<stdio.h>
#include<math.h>
int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        double sum=0.01*pow(2,n);
        printf("%lld\n",(long long int)sum);
    }
    return 0;
}