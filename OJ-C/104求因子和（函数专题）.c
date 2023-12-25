#include<stdio.h>
int FacSum(int n){
    int Sum=0,n1=n;
    for(int i=1;i<=n-1;i++){
        if(n%i==0) Sum+=i;
    }
    return Sum;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",FacSum(n));
    return 0;
}