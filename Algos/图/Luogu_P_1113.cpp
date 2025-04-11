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
int w[N];
void init(int n){
    idx=0;
    foe(i,0,n+1){
        st[i]=false;
        h[i]=-1;
        w[i]=0;
    }
}

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int res=0;
void dfs(int n){
    st[n]=true;
    int max_cnt=-1;
    for(auto p=h[n];p!=-1;p=ne[p]){
        auto j=e[p];
        if(st[j]) continue;
        st[j]=true;
        dfs(j);
        max_cnt=max(max_cnt,w[j]);
    }
    res+=max_cnt;
}
void printl(int n){
    foe(i,1,n+1){
        cout<<i<<':';
        for(auto p=h[i];p!=-1;p=ne[p]){
            auto j=e[p];
            cout<<j<<' ';
        }
        cout<<endl;
    }
}
void solve(){
    int n;
    cin>>n;
    init(n);
    int a;
    int no_l=0;
    foe(i,0,n){
        cin>>a;
        int b,len;
        cin>>len;
        w[a]=len;
        int cnt=0;
        while(true){
            cin>>b;
            if(!b) break;
            cnt++;
            add(b,a);
        }
        if(!cnt){
            no_l=a;
        }
        // printl(n);
        // cout<<"-------------"<<endl;
    }
    // printl(n);
    dfs(no_l);
    cout<<res+w[no_l]<<endl;
}


int main(){
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}