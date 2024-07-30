#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)

using namespace std;
using i32=signed;
const int N=10;

void solve(){
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int ans=0;
    foe(i,0,n-3){
        if(a.substr(i,3)=="x.x"&&b.substr(i,3)=="..."||a.substr(i,3)=="..."&&b.substr(i,3)=="x.x")
            ans++;

    }
    cout<<ans<<endl;
}
i32 main(){
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}