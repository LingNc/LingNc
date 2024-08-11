#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define all(a) a.begin(),a.end()
#define INF64 0x3f3f3f3f3f3f3f3f
#define INF32 0x3f3f3f3f
#define ll long long
#define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;

const i32 N=0;

void solve(){
    i64 a,b,c,d,e;
    cin>>a>>b>>c;
    if(a>=c)
        d=c;
    else d=a;
    if(b>=c)
        e=c;
    else e=b;
    cout<<d*e<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}