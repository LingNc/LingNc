#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){return b==0?a:gcd(b,a%b);}
template<typename iii> iii lcm(iii a,iii b){return a/gcd(a,b)*b;}
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

const i32 N=1<<8;

int val[N],win[N],n,tol;

int dfs(int u){
    if(u>=tol)
        return val[u];
    int l,r;
    //左子树
    l=dfs(2*u);
    //右子树
    r=dfs(2*u+1);
    if(l>r)
        win[u]=win[2*u];
    else
        win[u]=win[2*u+1];
    val[u]=max(l,r);
    return val[u];
}
void solve(){
    cin>>n;
    tol=1<<n;
    foe(i,1,tol){
        cin>>val[tol+i-1];
        win[tol+i-1]=i;
    }
    dfs(1);
    cout<<((val[2]>val[3])?win[3]:win[2])<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}