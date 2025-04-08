#include <bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

const int N=1e5+10;
struct Adj{
    int e[2*N],ne[2*N],h[N],idx;
    bool st[N];
    int w[N];
    void init(int n){
        idx=0;
        foe(i,0,n) h[i]=-1;
    }
    void add(int a,int b){
        e[idx]=b,ne[idx]=h[a],h[a]=idx++;
    }
    void add(int a,int b,int val){
        e[idx]=b,ne[idx]=h[a],h[a]=idx++;
        w[idx]=val;
    }
};