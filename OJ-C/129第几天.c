#include<stdio.h>
int is_leap(int year);
int M[12]={0,31,59,90,120,151,181,212,243,273,304,334};
int main(){
    int year,month,day,sum_day;
    scanf("%d-%d-%d",&year,&month,&day);
    sum_day=M[month-1]+day;
    if(is_leap(year)&&month>2) sum_day++;
    printf("%d",sum_day);
    return 0;
}
int is_leap(int year){
    if((year%4==0&&year%100!=0)||year%400==0)
        return 1;
    else
        return 0;
}