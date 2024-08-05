#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define all(a) a.begin(),a.end()

using namespace std;
using i32=signed;
using i64=long long;

const int N=20;
int e[2*N],ne[2*N],h[N],w[N],idx;
vector<int> path;
vector<int> ans;
double res=0,tmax=0;
double w2[N];
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void init(int nn){
    ans.clear();
    foe(i,0,nn){
        h[i]=-1;
        w2[i]=0;
    }
    idx=0;
    res=0;
    tmax=0;
}

double dfs(int val,int fa){
    int cnt=0;
    for(int p=h[val];p!=-1;p=ne[p]){
        int j=e[p];
        if(j!=fa){
            path.push_back(j);
            tmax+=w2[j];
            dfs(j,val);
            tmax-=w2[j];
            path.pop_back();
            cnt++;
        }
    }
    if(cnt==0){
        if(tmax>res){
            res=tmax;
            ans=path;
        }
    }
}
void solve(){
    int n;
    cin>>n;
    init(n);
    int a,b;
    foe(i,1,n-1){
        cin>>a>>b;
        add(a,b);
    }
    add(0,1);
    foe(i,1,n){
        cin>>w[i];
    }
    foe(i,1,n){
        w2[i]=15.0/(double)w[i];
    }
    dfs(0,0);
    cout<<res<<endl;
    for(auto &i:ans){
        
    }
    cout<<endl;
}
i32 main(){
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}