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

const i32 N=1e3+10;

int dp[500][1000],o[N],on[N],wgt[N];
int res=INF64,st[N];
int m,n,k;

int dfs(int i,int j){
    if(i<=0&&j<=0) return 0;
    int l=dfs(i-1,j);
    int r=dfs(i,j-1);
    
}

void solve(){
    cin>>m>>n;
    cin>>k;
    foe(i,1,k){
        cin>>o[i]>>on[i]>>wgt[i];
    }
    memset(dp,0x3f,sizeof dp);
    st[0]=true;
    dp[0][0]=0;
    dfs(0,0);
    cout<<res<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}