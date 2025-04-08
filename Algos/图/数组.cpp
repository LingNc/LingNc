#include <bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<( b);++i)
using namespace std;
const int N=1e5+10;
struct Adj{
    struct edge{
        int next,val;
        edge(){}
        edge(int next):next(next){}
        edge(int next,int val):next(next),val(val){}
    };
    vector<vector<edge>> h;
    bitset<N> st;
    Adj(int size=N){
        h.resize(size);
        st.reset();
    }
    void init(){
        foe(i,0,N){
            h[i].clear();
            st.reset();
        }
    }
    void add(int a,int b){
        h[a].push_back(edge(b));
    }
    void add(int a,int b,int val){
        h[a].push_back(edge(b,val));
    }
    vector<edge> &operator[](int index){
        return h[index];
    }
};