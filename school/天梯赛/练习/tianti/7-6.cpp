#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
// #define endl '\n'
using namespace std;
using i32=int;
using i64=long long;
#define int long long
#define all(a) a.begin(),a.end()
void solve(){
    string str;
    cin>>str;
    reverse(all(str));
    cout<<stoi(str)<<endl;
}

i32 main(){
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}