#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
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

const i32 N=0;

void solve(){
    int res=0,n,k;
    cin>>n>>k;
    vector<int> a(n,0);
    foe(i,0,n-1) cin>>a[i];
    sort(all(a));
    fod(i,n-1,0){
        res+=a[i--];
        if(i>=0){
            if(k>=a[i+1]-a[i]){
                k-=a[i+1]-a[i];
                res-=a[i+1];
            }
            else if(k>0){
                res-=a[i];
                res-=k;
                k=0;
            }
            else res-=a[i];
        }
    }
    cout<<res<<'\n';
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}