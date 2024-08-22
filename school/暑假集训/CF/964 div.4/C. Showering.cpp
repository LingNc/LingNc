#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define all(a) a.begin(),a.end()
#define yes(res) cout<<((res)?"YES":"NO")<<endl
using namespace std;
using i32=signed;
using i64=long long;

void solve(){
    int n,s,m;
    cin>>n>>s>>m;
    int l,r,rr=0;
    bool res=false;
    foe(i,1,n){
        cin>>l>>r;
        if(l-rr>=s) res=true;
        rr=r;
    }
    if(m-r>=s) res=true;
    yes(res);
}
i32 main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}

