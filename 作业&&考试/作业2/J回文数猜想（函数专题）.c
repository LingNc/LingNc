#include<stdio.h>
int inverse(int n);
int main(){
    int n;
    scanf("%d",&n);
    int m;
    while(m=inverse(n),m!=n){
        printf("%d ",n);
        n=m+n;
    }
    printf("%d",m);
    return 0;
}
int inverse(int n){
    int num=n,result=0;
    while(num){
        result=10*(num%10+result);
        num/=10;
    }
    return result/10;
}