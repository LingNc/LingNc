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
    int n,m;
    cin>>n>>m;
    if(m%2&&n||!(m%2)&&!n) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
i32 main(){
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}