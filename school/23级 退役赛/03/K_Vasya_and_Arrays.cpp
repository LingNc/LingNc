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
    int n,m;
    int pa=0,pb=0;
    int res=0;
    int ta,tb;
    scanf("%lld",&n);
    vector<int> a(n+1,0);
    foe(i,1,n+1){
        scanf("%lld",&ta);
        a[i]=a[i-1]+ta;
    }
    scanf("%lld",&m);
    vector<int> b(m+1,0);
    foe(i,1,m+1){
        scanf("%lld",&tb);
        b[i]=b[i-1]+tb;
    }
    while(1){
        if(a[pa]==b[pb]){
            pa++,pb++;
            res++;
        }
        else if(a[pa]<b[pb]) pa++;
        else if(a[pa]>b[pb]) pb++;
        if(pa>=n||pb>=m) break;
    }
    if(a[n]==b[m]) printf("%lld\n",res);
    else printf("%d\n",-1);
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}