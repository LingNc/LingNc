#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return (b==0)?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
using i32=int;
using i64=long long;
#define int long long
#define endl '\n'
#define all(a) a.begin(),a.end()
using namespace std;
using arr=vector<int>;
using PII=pair<int,int>;

const int N=1e6+10;

int e[2*N],ne[2*N],h[N];
bool st[N]={ 0 };
int idx=0;
void init(){
    foe(i,0,N){
        h[i]=-1;
        st[i]=0;
    }
}
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

vector<int> res1,res2;

void dfs(int n){
    st[n]=true;
    res1.push_back(n);
    vector<int> temp;
    for(int p=h[n];p!=-1;p=ne[p]){
        auto j=e[p];
        if(st[j]) continue;
        temp.push_back(j);
    }
    sort(all(temp));
    for(auto &it:temp){
        if(st[it]) continue;
        st[it]=true;
        dfs(it);
    }
}

void bfs(){
    queue<int> q;
    q.push(1);
    st[1]=true;
    while(!q.empty()){
        auto &t=q.front();
        q.pop();
        res2.push_back(t);
        vector<int> temp;
        for(auto p=h[t];p!=-1;p=ne[p]){
            if(st[e[p]]) continue;
            st[e[p]]=true;
            temp.push_back(e[p]);
        }
        sort(all(temp));
        for(auto &it:temp){
            q.push(it);
        }
    }
}

void solve(){
    init();
    int n,m;
    cin>>n>>m;
    int a,b;
    foe(i,0,m){
        cin>>a>>b;
        add(a,b);
        // add(b,a);
    }
    res1.clear();
    res2.clear();
    dfs(1);
    foe(i,0,res1.size()){
        if(i) cout<<' ';
        cout<<res1[i];
    }
    cout<<endl;
    foe(i,0,n+1) st[i]=false;
    bfs();
    foe(i,0,res2.size()){
        if(i) cout<<' ';
        cout<<res2[i];
    }
    cout<<endl;
}

i32 main(){
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}