#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
//#define endl '\n'
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define PII pair<int,int>
using i32=int;
#define int long long

int mm[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
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
    bool is_lap(){
        if(year%4==0&&year%100!=0||year%100==0&&year%400==0){
            return true;
        }
        else{
            return false;
        }
    }
    int to_days(){

    }
    int to_secs(){

    }
};

void solve(){
    int a[13];
    a[0]=0;
    foe(i,1,13){
        a[i]=a[i-1]+mm[i];
    }
    foe(i,0,13) cout<<a[i]<<',';
}

i32 main(){
	IOS;
	i32 T=1;
	// cin>>T;
	while(T--) solve();
}
