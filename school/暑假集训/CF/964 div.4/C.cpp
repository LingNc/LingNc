#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define all(a) a.begin(),a.end()

using namespace std;
using i32=signed;
using i64=long long;

void solve(){
    int n,m,k,y,v,s,x;
    cin>>n>>m>>k;
        cin>>x>>y;
        v=0;
        if(x>=m)v=1;
        for(int i=1;i<n;i++){
            s=y;
            cin>>x>>y;
            if(x-s>=m){
                v=1;
            }
        }
        if(k-y>=m)v=1;
        if(v) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
}
i32 main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}

