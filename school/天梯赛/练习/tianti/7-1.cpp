#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
#define endl '\n'
using namespace std;
using i32=int;
using i64=long long;
#define int long long

void solve(){
    string str;
    cin>>str;
    string year=str.substr(6);
    string day=str.substr(3,2);
    string mm=str.substr(0,2);
    cout<<year<<'-'<<mm<<'-'<<day<<endl;

}

i32 main(){
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}