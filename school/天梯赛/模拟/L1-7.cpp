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
    int a,b,n;
    cin>>a>>b>>n;
    vector<int> res;
    res.push_back(a);
    res.push_back(b);
    int i=0;
    int k=2*n;
    while(k--){
        int t=res[i]*res[i+1];
        i++;
        vector<int> tt;
        if(t)
            while(t){
                tt.push_back(t%10);
                t/=10;
            }
        else{
            tt.push_back(t);
        }
        while(!tt.empty()){
            res.push_back(tt.back());
            tt.pop_back();
        }
    }
    // while(res.size()<n){
    //     res.push_back(0);
    // }
    foe(i,0,n){
        if(i!=0) cout<<' ';
        cout<<res[i];
    }
}
i32 main(){
    IOS;
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}
