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

const i32 N=1e5+10;

map<int,bool> best;
void init(){
    foe(i,1,1001){
        best[i*i*i]=1;
    }
    foe(i,1,31623){
        best[i*i]=1;
    }
}
void solve(){
    int n;
    cin>>n;
    int ans=0;
    for(auto &it:best){
        if(it.first<=n) ans++;
        else break;
    }
    cout<<ans<<endl;
}
i32 main(){
    init();
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}