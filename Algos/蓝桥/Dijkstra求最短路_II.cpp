#include<bits/stdc++.h>
using namespace std;
using i32=int;
using i64=long long;
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
using arr=vector<int>;
using PII=pair<int,int>;
#define endl '\n'
#define IOS std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define INF32 0x3f3f3f3f

const int N=2e5+10;

int e[2*N],ne[2*N],h[N],idx=0,w[N];
bool st[N];

void init(){
    memset(e,0,sizeof(e));
    memset(ne,0,sizeof(ne));
    memset(h,-1,sizeof(h));
    memset(w,0,sizeof(w));
    memset(st,false,sizeof(st));
    idx=0;
}
void clear(int n){
    foe(i,0,n+1){
        st[i]=-1;
    }
}

void add(int a,int b,int val){
    w[idx]=val;
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
typedef pair<int,int> PII;
typedef vector<int> arr;
void print(int n){
    foe(i,1,n+1){
        cout<<i<<": ";
        for(auto p=h[i];p!=-1;p=ne[p]){
            auto j=e[p];
            cout<<j<<' ';
        }
        cout<<endl;
    }
    cout<<"--------------"<<endl;
}
int Dijkstra(int n){
    int dist[N];
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({ 0,1 });
    while(!heap.empty()){
        auto t=heap.top();
        heap.pop();
        auto ver=t.second,distant=t.first;
        if(st[ver]) continue;
        st[ver]=true;
        for(auto p=h[t.second];p!=-1;p=ne[p]){
            auto j=e[p];
            if(dist[j]>distant+w[p]){
                dist[j]=distant+w[p];
                heap.push({ dist[j],j });
            }
        }
    }
    if(dist[n]==INF32) return -1;
    else return dist[n];
}

void solve(){
    // 初始化
    init();
    int n,m;
    cin>>n>>m;
    int a,b,val;
    foe(i,0,m){
        cin>>a>>b>>val;
        add(a,b,val);
        // add(b,a,val);
    }
    // print(n);
    cout<<Dijkstra(n)<<endl;
}

i32 main(){
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}
