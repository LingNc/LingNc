#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define all(a) a.begin(),a.end()

using namespace std;
using i32=signed;
using i64=long long;

int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
int lcm(int a,int b){ return a/gcd(a,b)*b; }
const int N=3e5+10;
int e[2*N],ne[2*N],h[N],idx;

void init(){
    memset(h,-1,sizeof h);
    idx=0;
}
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int dfs(int val,int fa,int xory){
    int len=1;
    for(int p=h[val];p!=-1;p=ne[p]){
        int j=e[p];
        if(j!=fa&&j!=xory){
            len+=dfs(j,val,xory);
        }
    }
    return len;
}

void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    init();
    int a,b;
    foe(i,1,n-1){
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    int sx,sy;
    sx=dfs(x,0,y);
    sy=dfs(y,0,x);
    int rx=n-sy,ry=n-sx;
    cout<<rx*ry<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}