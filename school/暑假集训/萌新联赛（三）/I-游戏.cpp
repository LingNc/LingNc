#include<bits/stdc++.h>
#define int long long 
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define all(a) a.begin(),a.end()
#define INF 0x3f3f3f3f3f3f3f3f

using i32=signed;
using i64=long long;
using namespace std;

const int N=1e6+10;
int e[2*N],ne[2*N],h[N],idx,w[2*N];
bool tim[2*N],st[N];
int dist[N];

int n,m,k;
typedef pair<int,int> PII;


void init(){
    memset(h,-1,sizeof h);
    idx=0;
}
void add(int a,int b,int c,bool d){
    w[idx]=c,tim[idx]=d;
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
//覆盖状态
void set_tim(bool x){
    foe(i,0,2*N-1) tim[i]=x;
}
//版子
//mlogn
// val结点开始
void Dijkstra(int val){
    priority_queue<PII> heap;

    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);
    dist[val]=0;
    heap.push({0,val});
    
    //无论走不走到k的最小距离
    while(heap.size()){
        //找到未确定的距离最小的点
        auto t=heap.top();
        heap.pop();
        //已经存在过 冗余
        if(st[t.second]==true) continue;
        st[t.second]=true;
        
        // 判断从该点(t)出发的所有路径的点的距离最小值
        for(int p=h[t.second];p!=-1;p=ne[p]){
            int j=e[p];
            //状态可以走
            if(t.first+w[p]<dist[j]&&tim[p]){
                dist[j]=t.first+w[p];
                heap.push({dist[j],j});
            }
        }
    }
}

void solve(){
    cin>>n>>m>>k;
    init();
    int a,b,c,d;
    foe(i,1,m){
        cin>>a>>b>>c>>d;
        add(a,b,c,d);
        add(b,a,c,d);
    }
    Dijkstra(1);
    int res=dist[n],min_k=dist[k];
    set_tim(true);

    Dijkstra(k);
    res=min(dist[n]+min_k,res);
    
    if(res==INF) res=-1;
    cout<<res<<endl;
}

i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}
