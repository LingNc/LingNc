#include<bits/stdc++.h>
#include"A.cpp"

//vector有O2优化版
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
}adj;

//原生数组版
const int N=1e6+10;
typedef struct Adj{
    int h[N],e[2*N],ne[2*N],idx;
    bool st[N];
    int w[N];
    //初始化
    void init(int n){
        foe(i,0,n) h[i]=-1;
        idx=0;
    }
    //加边
    void add(int a,int b){
        e[idx]=b,ne[idx]=h[a],h[a]=idx++;
    }
    //带权加边
    void add(int a,int b,int c){
        w[idx]=c;
        e[idx]=b,ne[idx]=h[a],h[a]=idx++;
    }
}adj;