#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
// #define endl '\n'
using namespace std;
using i32=int;
using i64=long long;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> res(n+1,0);
    res[1]=1,res[2]=2;
    foe(i,3,n+1){
        res[i]=res[i-1]+res[i-2];        
    }
    foe(i,1,n+1){
        if(i!=1) cout<<' ';
        cout<<res[i];
    }
}

i32 main(){
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}