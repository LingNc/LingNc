#include<stdio.h>
int digitSum(int n);
int main(){
    int n;
    scanf("%d",&n);
    while(1){
        if(digitSum(n)<10)
            break;
        else
            n=digitSum(n);
    }
    printf("%d",digitSum(n));
    return 0;
}
int digitSum(int n){
    int num=n,Sum=0;
    while(num>0){
        Sum+=num%10;
        num/=10;
    }
    return Sum;
}