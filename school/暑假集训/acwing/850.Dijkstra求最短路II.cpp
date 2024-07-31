#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<queue>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;
//记得1e5+10
//稀疏图n~m
//用邻接表
const int N=1e6+10;
int n,m,dist[N];
int h[N],e[N],ne[N],idx,w[N];//w[N]idx对应的权重
//是否是已经确定的点
bool st[N];
typedef pair<int,int> PII;
priority_queue<PII,vector<PII>,greater<PII>> heap;

//初始化
void init(){
    memset(h,-1,sizeof(h));
    idx=0;
}
//添加单向边
void add(int a,int b,int c){
    //给a->b权重
    w[idx]=c;
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
    
}
//堆优化版 稀疏图 n~m(当n很大的时候用 1e5)
//mlogn
//记得init()初始化 忘了该超时了
//记得改 const int N=1e6+10 段错误
int Dijkstra(){
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    heap.push({0,1});
    //遍历所有点
    while(heap.size()){
        //用小顶堆（优先队列实现）找到未确定的距离最小的点
        auto t=heap.top();
        heap.pop();
        //确定这个路径最小
        //已经存在过 冗余
        if(st[t.second]==true) continue;
        //else st[t.second]=true 这个就错了
        st[t.second]=true;
        
        //if(t==n) break;
        // 判断从该点(t)出发的所有路径的点的距离最小值
        for(int p=h[t.second];p!=-1;p=ne[p]){
            int j=e[p];
            if(t.first+w[p]<dist[j]){
                dist[j]=t.first+w[p];
                heap.push({dist[j],j});
            }
            // dist[j]=min(dist[j],t.first+w[p]);
            // heap.push({dist[j],j});
        }
    }
    return (dist[n]==0x3f3f3f3f)?-1:dist[n];
}
signed main(){
    cin>>n>>m;
    //初始化链表
    init();
    int x,y,c;
    foe(i,1,m){
        cin>>x>>y>>c;
        add(x,y,c);
    }
    int t=Dijkstra();
    cout<<t<<endl;
    
    return 0;
}
/*
3 3
1 2 2
2 3 1
1 3 4

3
*/