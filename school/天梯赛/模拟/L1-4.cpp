#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
#define endl '\n'
using i32=int;
using i64=long long;
using namespace std;
#define int long long
typedef vector<int> arr;
using PII=pair<int,int>;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define all(a) a.begin(),a.end();

void solve(){
    vector<int> a;
    int t;
    while(true){
        cin>>t;
        if(t==1) a.push_back(1);
        else if(t==0) cout<<a.size()<<endl;
        else break;
    }
}
i32 main(){
    IOS;
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}
