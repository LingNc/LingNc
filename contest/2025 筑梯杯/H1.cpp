#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
//#define endl '\n'
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define PII pair<int,int>
using i32=int;
#define int long long

int mm[]={31,28,31,30,31,30,31,31,30,31,30,31};
int m2[]={0,31,59,90,120,151,181,212,243,273,304,334,365};
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
    bool is_lap(int years){
        if((years%4==0&&years%100!=0)||(years%100==0&&years%400==0)){
            return true;
        }
        else{
            return false;
        }
    }
    int to_days(){
        int res=0;
        res+=m2[month-1];
        res+=day-1;
        if(is_lap(year)&&(month>2)){
            res++;
        }
        return res;
    }
    int to_secs(){
        int res=0;
        int days=0;
        foe(i,2000,year){
            days+=365;
            if(is_lap(i)){
                days++;
            }
        }
        days+=to_days();
        res+=days*3600*24;
        // time
        res+=hour*3600;
        res+=min*60;
        res+=sec;
        return res;
    }
};

int eight=8*3600;

void solve(){
    string s,v;
    cin>>s;
    cin>>v;
    Time a,b;
    a.read(s);
    b.read(v);
    int a_sec=a.to_secs();
    int b_sec=b.to_secs();
    bool ans=false;
    if(b_sec-a_sec>=eight){
        ans=true;
    }
    if(ans){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}

i32 main(){
	IOS;
	i32 T=1;
	cin>>T;
	while(T--) solve();
}
