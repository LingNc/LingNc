#include<stdio.h>
int inverse(int number){
    int S=0;
    while(number>0){
        S=(S+number%10)*10;
        number/=10;
    }
    return S/10;
}

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i=m;i<=n;i++){
        if(i==inverse(i)) printf("%d ",i);
    }
    return 0;
}