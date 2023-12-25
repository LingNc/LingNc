#include<stdio.h>
#include<math.h>
int inverse(int num){
    int num1,num2,s=0,n=0;
    num2=num1=num;
    while(num1>=10){
        num1/=10;
        n++;
    }
    for(int i=0;i<=n;i++){
        s+=(num2%10)*pow(10,n-i);
        num2/=10;
    }
    return s;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",inverse(n));
    return 0;
}