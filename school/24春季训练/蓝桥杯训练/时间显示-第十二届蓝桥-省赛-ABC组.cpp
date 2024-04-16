#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)

using namespace std;
int run(int year);
int main(){
    ll time_0;
    cin>>time_0;
    ll time=time_0/1000;
    ll year_sec=365*24*60*60;
    ll day_sec=24*60*60;
    ll now=1970;
    while(1){
        if(run(now)){
            if(time<year_sec+day_sec) break;
            time-=year_sec+day_sec;
        }
        else{
            if(time<year_sec) break;
            time-=year_sec;
        }
        now++;
    }
    ll tian=time%day_sec;
    int hour=tian/3600;
    int min=(tian%3600)/60;
    int sec=(tian%3600)%60;
    string data;
    if(hour<10){
        cout<<0<<hour<<':';
    }
    else
        cout<<hour<<':';
    if(min<10)
        cout<<0<<min<<':';
    else
        cout<<min<<':';
    if(sec<10)
        cout<<0<<sec;
    else
        cout<<sec;
    return 0;
}

int run(int year){
    if(year%4==0&&year%100!=0||year%100==0&&year%400==0)
        return 1;
    else
        return 0;
}