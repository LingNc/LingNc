#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define yes(res) cout<<((res)?"YES":"NO")<<'\n'
#define foe(i,a,b) for(int i=(a);i<(b);i++)
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
    int N;
    cin>>N;
    arr a(N+1,0),b(N+1,0);
    foe(i,1,N+1) cin>>a[i];
    int t=-N+1;
    arr c(N+1,0);
    foe(i,1,N+1){
        c[i]=t+a[i];
        t+=2;
    }
    arr d(N+1,0);
    foe(i,1,N+1){
        b[i]=c[i]-c[i-1];
        // d[i]=a[i]-a[i-1];
    }
    foe(i,1,N+1){
        // c[i]=c[i-1]+b[i];
        if(c[i]>=0) continue;
        b[N+c[i]+1]--;
        b[i]-=c[i];
        b[i+1]+=c[i];
    }
    foe(i,1,N+1) c[i]=c[i-1]+b[i];
    foe(i,1,N+1) cout<<c[i]<<' ';
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}
/*


*/