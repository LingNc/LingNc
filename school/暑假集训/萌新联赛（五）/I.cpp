#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){return b==0?a:gcd(b,a%b);}
template<typename iii> iii lcm(iii a,iii b){return a/gcd(a,b)*b;}
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define all(a) a.begin(),a.end()
#define INF64 0x3f3f3f3f3f3f3f3f
#define INF32 0x3f3f3f3f
#define int long long
#define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;

const i32 N=1e6+10;

int m[N];
void solve(){
    int n;
    cin>>n;
    foe(i,1,n) cin>>m[i];
    sort(m+1,m+n+1);
    int t;
    if(!(n%2)) t=n/2;
    else t=n/2+1;
    int res=0;
    foe(i,1,n){
        res+=fabs(m[t]-m[i]);
    } 
    cout<<res+1<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}