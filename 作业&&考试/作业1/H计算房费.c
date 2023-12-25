#include<stdio.h>
int main(){
    int number;
    float rate=0;
    scanf("%d",&number);
    if(number==1)
        rate=1;
    else if(number<10)
        rate=0.9;
    else if(number<20)
        rate=0.8;
    else
        rate=0.7;
    float price=356*number*rate;
    printf("%.1f",price);
    return 0;
}