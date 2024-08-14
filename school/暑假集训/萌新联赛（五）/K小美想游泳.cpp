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

const int N=1e4+10;
typedef struct Adj{
    //边
    struct edge{
        int val,next;
        edge(int next):next(next){}
        edge(int val,int next):val(val),next(next){}
    };
    //邻接表
    vector<vector<edge>> mp;
    //有没有走过
    vector<char> st;
    //指定最大节点数量
    Adj(i64 N):mp(N,vector<edge>()),st(N,0){}
    //初始化
    Adj(i64 N,int n):mp(N,vector<edge>()),st(N,0){
        init(n);
    }
    auto &operator[](int i){
        return mp[i];
    }
    //初始化的节点个数
    void init(int n){
        foe(i,0,n){
            mp[i].clear();
            st[i]=false;
        }
    }
    //加边
    void add(int a,int b){
        mp[a].push_back(edge(b));
    }
    void add(int a,int b,int val){
        mp[a].push_back(edge(val,b));
    }
}Adj;

Adj adj(N);

typedef pair<int,int> PII;
int Dijkstra(int s,int e){
    vector<int> dist(N,INF32);
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    dist[s]=0;
    heap.push({0,s});
    while(heap.size()){
        auto t=heap.top();
        heap.pop();
        if(adj.st[t.second]) continue;
        adj.st[t.second]=true;

        foe(p,0,adj[t.second].size()-1){
            auto j=adj[t.second][p];
            if(adj.st[j.next]) continue;
            int a=max(j.val,dist[t.second]);
            if(a<dist[j.next]){
                dist[j.next]=a;
                heap.push({dist[j.next],j.next});
            }
        }
    }
    return (dist[e]==INF32)?-1:dist[e];
}

signed main(){
    int n,m;
    cin>>n>>m;
    adj.init(n);
    int x,y,c;
    foe(i,1,m){
        cin>>x>>y>>c;
        adj.add(x,y,c);
        adj.add(y,x,c);
    }
    int s,e;
    cin>>s>>e;
    cout<<Dijkstra(s,e)<<endl;
    return 0;
}
