#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
using namespace std;
using i32=int;
using i64=long long;
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using arr=vector<int>;
using PII=pair<int,int>;

const int N=1e5+10;
int e[2*N],ne[2*N],h[N],idx=0;
bool st[N];

void init(int n){
    foe(i,0,n+1){
        st[i]=false;
        h[i]=-1;
    }
}

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int res[N]={ 0 };
void dfs(int n,int ans){
    if(st[n]) return;
    res[n]=ans;
    st[n]=true;
    for(auto p=h[n];p!=-1;p=ne[p]){
        if(st[e[p]]) continue;
        dfs(e[p],ans);
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    init(n);
    int a,b;
    foe(i,0,m){
        cin>>a>>b;
        // add(a,b);
        add(b,a);
    }
    fod(i,n,0){
        dfs(i,i);
    }
    foe(i,1,n+1){
        if(i!=1) cout<<' ';
        cout<<res[i];
    }
    cout<<endl;
}


int main(){
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}