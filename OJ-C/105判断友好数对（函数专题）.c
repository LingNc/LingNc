#include<stdio.h>
int facsum(int n){
    int Sum=0,n1=n;
    for(int i=1;i<=n-1;i++){
        if(n%i==0) Sum+=i;
    }
    return Sum;
}
int main(){
    int m,n,result=0;
    scanf("%d %d",&m,&n);
    for(int i=m;i<=n;i++){
        int fac=facsum(i);
        if(
            fac<=n
            &&fac>=m
            &&i<fac
            &&i==facsum(fac)
        ){
            printf("%d %d\n",i,fac);
            result+=1;
        }
    }
    if(result==0) printf("No answer");
    return 0;
}