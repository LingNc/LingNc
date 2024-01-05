#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int data_day(int month,int day);
int month_days(int month);
int happy_level(int days);
int main(){
    int T;
    cin>>T;
    while(T--){
        int M,D;
        scanf("%d %d",&M,&D);
        int flag=happy_level(data_day(M,D));
        if(flag==0)
            puts("Sad");
        else if(flag==1)
            puts("Happy");
        else
            puts("Happy!!!");
    }
    return 0;
}
int happy_level(int days){
    if(days>=12&&days<=41)
        return 1;
    else if(days>=182&&days<=244)
        return 2;
    else if(days%7==1||days%7==0)
        return 1;
    else return 0;
}
int data_day(int month,int day){
    int sum=0;
    for(int i=1;i<=month-1;i++){
        sum+=month_days(i);
    }
    return sum+day;
}
int month_days(int month){
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
        return 31;
    }
    else{
        if(month==2)
            return 28;
        else
            return 30;
    }
}