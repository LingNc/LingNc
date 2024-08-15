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

int M,ti;
int t[N],w[N];
int mem[N][N];
int dfs(int u,int last){
    if(last<0) return -INF32;
    if(mem[u][last]!=-1) return mem[u][last];
    if(u==M+1) return mem[u][last]=0;
    return mem[u][last]=max(dfs(u+1,last-t[u])+w[u],dfs(u+1,last));
}

void solve(){
    memset(mem,-1,sizeof mem);
    cin>>ti>>M;
    foe(i,1,M) cin>>t[i]>>w[i];
    cout<<dfs(1,ti)<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}