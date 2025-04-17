#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
#define endl '\n'
#define IOS std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define INF32 0x3f3f3f3f
#define int long long
using namespace std;
using i32=signed;
using i64=long long;


const int N=1e3+10;
int e[2*N],ne[2*N],w[N],h[N],idx=0;
bool st[N];

void init(int n){
    foe(i,0,n+1){
        st[i]=0;
        h[i]=-1;
        w[i]=0;
    }
    memset(e,0,sizeof(e));
    memset(ne,0,sizeof(ne));
}

void add(int a,int b,int val){
    w[idx]=val;
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void solve(){
    int n,m,s,d;
    cin>>n>>m>>s>>d;
    init(n);

}
i32 main(){
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}