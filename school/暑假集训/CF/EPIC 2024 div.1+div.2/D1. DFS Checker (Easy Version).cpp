#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
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

const i32 N=1e5+10;

//边
struct edge{
    int val,next;
    edge(int next):next(next){}
};
//邻接表
vector<vector<edge>> adj(N,vector<edge>());
vector<int> fa(N);

//初始化，读入所需要的节点数量
void init(int n){
    foe(i,0,n) mp[i].clear();
}
//加边
void add(int a,int b){
    mp[a].push_back(edge(b));
}




void dfs(int val,int fa){
    if(lis.mp[val].empty()){

    }
    for(auto &i:lis.mp[val]){
        int j=i.next;
        if(j!=fa) dfs(j,val);
    }
}
void solve(){
    int n,q;
    cin>>n>>q;
    lis.init(n);
    vector<int> fa(n+1,0);
    foe(i,2,n){
        cin>>fa[i];
        lis.add(fa[i],i);
    }
    vector<int> a(n,0);
    foe(i,0,n-1) cin>>a[i];

}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}