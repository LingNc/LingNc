#include<bits/stdc++.h>
#define int long long 
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)

using i32=signed;
using namespace std;


void solve(){
    int n;
    cin>>n;
    if(n!=0) cout<<2+n*(n-1)<<' ';
    else cout<<1<<' ';
}

i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}