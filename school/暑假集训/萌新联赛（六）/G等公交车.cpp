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
typedef vector<int> arr;
typedef pair<int,int> PII;

const i32 N=0;

void solve(){
    int n,m;
    cin>>n>>m;
    arr a(n,0);
    foe(i,0,n-1) cin>>a[i];
    arr b(m,0);
    foe(i,0,m-1) cin>>b[i];
    int q;
    cin>>q;
    int t,x;
    foe(i,1,q){
        cin>>t>>x;
        int ans=t-a[x-1];
        auto res=lower_bound(all(b),ans);
        if(res==b.end()) cout<<"TNT"<<endl;
        else cout<<*res-ans<<endl;
    }

}
i32 main(){
    IOS;
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}