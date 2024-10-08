#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){return b==0?a:gcd(b,a%b);}
template<typename iii> iii lcm(iii a,iii b){return a/gcd(a,b)*b;}
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define yes(res) cout<<((res)?"YES":"NO")<<'\n'
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define all(a) a.begin(),a.end()
#define INF64 0x3f3f3f3f3f3f3f3f
#define INF32 0x3f3f3f3f
// #define int long long
#define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;
typedef vector<int> arr;
typedef pair<int,int> PII;

//记得1e5+10
//稀疏图n~m
//用邻接表
const int N=20;
int n,m,num_h,dist_map[2][N];
int h[2][N],e[2][N],ne[2][N],idx[2],w[2][N];//w[N]idx对应的权重
//是否是已经确定的点
bool st[2][N],have[N],use;
//默认排序函数是less<T>，记得写greater<T>


//初始化
void init(){
    foe(i,0,n+10){
        h[i]=-1;
        have[i]=0;
        w[i]=0;
        ne[i]=0;
        e[i]=0;
    }
    idx=0;
}
//添加单向边
void add(int a,int b,int c){
    //给a->b权重
    w[0][idx[0]]=c;
    w[1][dix[1]]=c/2;
    foe(i,0,1){
        e[i][idx[i]]=b,ne[i][idx[i]]=h[i][a],h[i][a]=idx[i]++;
    }
}
void add_h(int num){
    
}
//堆优化版 稀疏图 n~m(当n很大的时候用 1e5)
//mlogn
//记得init()初始化 忘了该超时了
//记得改 const int N=1e6+10 段错误
//多次Dijs距离dist[n]如果存在inf的时候求和有可能小于0 res=(dist[n]+inf,res)<0答案直接错误

int Dijkstra(int start,bool h_h,int f){
    use=0;
    auto dist=dist_map[f];

    foe(i,0,n){
        dist[i]=INF32;
        st[i]=0;
    }
    dist[start]=0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,start});
    //遍历所有点
    while(heap.size()){
        //用小顶堆（优先队列实现）找到未确定的距离最小的点
        auto t=heap.top();
        heap.pop();
        
        if(have[t.second]) use=1;

         //已经存在过 冗余
        if(st[t.second]==true) continue;
        st[t.second]=true;

        // 判断从该点(t)出发的所有路径的点的距离最小值
        for(int p=h[t.second];p!=-1;p=ne[p]){
            int j=e[p];
            if(st[j]) continue;
            if(use&&h_h) w[p]/=2;
            if(t.first+w[p]<dist[j]){
                dist[j]=t.first+w[p];
                heap.push({dist[j],j});
            }
        }
    }
    if(start==1) 
        return (dist[n]==INF32)?-1:dist[n];
    else
        return (dist[1]==INF32)?-1:dist[1];
}

void solve(){
    cin>>n>>m>>num_h;
    init();
    int num;
    foe(i,1,num_h){
        cin>>num;
        have[num]=1;
    }
    int u,v,w;
    foe(i,1,m){
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    int res0=Dijkstra(1,1,0);
    int res1=Dijkstra(n,1,1);
    arr res(n+1,0);
    int ans=INF32;
    foe(i,1,n){
        res[i]=max(dist_map[0][i],dist_map[1][i]);
        ans=min(ans,res[i]);
    }
    cout<<ans<<endl;
}

i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}

