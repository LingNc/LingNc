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

const i32 N=2e5+10;
typedef struct DSU{
    int p[N],cnt[N];
    //找祖源、压缩路径
    int find(int x){
        if(p[x]!=x)  p[x]=find(p[x]);
        return p[x];
    }
    // 初始化 n 为点数
    void init(int n){
        foe(i,0,n+1){
            p[i]=i;
            cnt[i]=1;
        }
    }
    // 加边
    void add(int u,int v){
        if(find(u)==find(v))
            return;
        cnt[find(v)]+=cnt[find(u)];
        p[find(u)]=find(v);
    }
    // 是否连通
    bool touch(int u,int v){
        if(find(u)==find(v))
            return true;
        else
            return false;
    }
    // u所在连通分量中有几个点
    int num(int u){
        return cnt[find(u)];
    }
}dsu;

dsu F,G;

void solve(){
    int n,m1,m2;
    cin>>n>>m1>>m2;
    F.init(n);
    G.init(n);
    int u,v;
    foe(i,0,m1){
        cin>>u>>v;
        F.add(u,v);
    }
    foe(i,0,m2){
        cin>>u>>v;
        G.add(u,v);
    }
    // 记录每个连通分量的根节点
    unordered_map<int,vector<int>> G_components;
    foe(i,1,n+1){
        int root=G.find(i);
        G_components[root].push_back(i);
    }

    // 总需要断开的边数和需要添加的边数
    int total_remove=0,total_add=0;

    // 对于 G 中的每个连通分量，计算 F 中需要断开和添加的边数
    for(auto &[root,nodes]:G_components){
        unordered_set<int> F_roots;
        for(int node:nodes){
            F_roots.insert(F.find(node));
        }

        // 需要断开的边数
        int remove_edges=F_roots.size()-1;
        total_remove+=remove_edges;

        // 需要添加的边数
        int add_edges=nodes.size()-1-(F_roots.size()-1);
        total_add+=add_edges;
    }
    cout<<total_remove+total_add<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}