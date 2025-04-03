#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define yes(res) cout<<((res)?"YES":"NO")<<'\n'
#define foe(i,a,b) for(int i=(a);i<(b);i++)
#define fod(i,a,b) for(int i=(a);i>(b);i--)
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
    int n;
    cin>>n;
    vector<int> p(n+1),d(n+1);
    for(int i=1; i<=n; ++i){
        cin>>p[i];
    }
    for(int i=1; i<=n; ++i){
        cin>>d[i];
    }

    vector<bool> used(n+1,false);
    vector<int> res(n+1,0);
    int zeros=0;

    for(int i=1; i<=n; ++i){
        int pos=d[i];
        if(p[pos]!=0){
            used[p[pos]]=true;
            p[pos]=0;
            zeros++;
        }
        res[i]=zeros;
    }

    for(int i=1; i<=n; ++i){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}