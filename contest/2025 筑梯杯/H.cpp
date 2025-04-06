#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
//#define endl '\n'
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define PII pair<int,int>
using i32=int;
#define int long long

struct Time{
    int year,month,day,hour,min,sec;
    Time(){}
    Time(const string &str){
        this->read(str);
    }
    Time& read(const string &str){
        year=atoi(str.substr(0,4).c_str());
        month=atoi(str.substr(5,7).c_str());
        day=atoi(str.substr(8,10).c_str());
        hour=atoi(str.substr(11,13).c_str());
        min=atoi(str.substr(14,16).c_str());    
        sec=atoi(str.substr(17).c_str());
        return *this;
    }
};

void solve(){
    string s,v;
    cin>>s;
    cin>>v;
    Time a,b;
    a.read(s);
    b.read(v);
    a.hour=a.hour+8;
    if(a.hour>=24){
        a.hour=a.hour%24;
        a.day++;
        if(a.month==1||a.month==3||a.month==5||a.month==7||a.month==8||a.month==10||a.month==12){
            if(a.day>31)a.day=a.day%31;
            a.month++;
            if(a.month==13)a.month=1;
            a.year++;
        }
        else if(a.month==2){
            if((a.year%4==0&&a.year%100!=0)||(a.year%100==0&&a.year%400==0)){
                if(a.day>29)a.day=1;
                a.month=3;
            }
            else{
                if(a.day>28)a.day=1;
                a.month=4;
            }
        }
        else{
           if(a.day>30)a.day=1;
                a.month++;
        }

    }
    if(a.year<=b.year){
        if(a.month<=b.month){
            if(a.day<=b.day){
                if(a.hour<=b.hour){
                    if(a.min<=b.min){
                        if(a.sec<=b.sec){
                               cout<<"Yes"<<endl;
                        }else cout<<"No"<<endl;
                    }else cout<<"No"<<endl;
                }else cout<<"No"<<endl;
            }else cout<<"No"<<endl;
        }
        else cout<<"No"<<endl;
    }
    else cout<<"No"<<endl;
}

i32 main(){
	IOS;
	i32 T=1;
	cin>>T;
	while(T--) solve();
}
