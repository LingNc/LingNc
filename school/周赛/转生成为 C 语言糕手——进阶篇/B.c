#include<stdio.h>
int leap(int);
int main(){
    int flag=0;
    for(int i=1001;i<=2023;i++){
        if(leap(i)) flag++;
    }
    printf("%d",flag);
    return 0;
}
int leap(int year){
    if((year%4==0&&year%100!=0)||(year%100==0&&year%400==0))
        return 1;
    else return 0;
}
