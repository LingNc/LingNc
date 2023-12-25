#include<stdio.h>
int main(){
    long long int num;
    scanf("%lld",&num);
    int n;
    if(num>5&&num%2!=0){
        printf("%d",3);
        return 0;
    }
    else{
        printf("%d",2);
        return 0;
    }
}