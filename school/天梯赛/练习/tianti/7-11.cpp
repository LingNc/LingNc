#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
// #define endl '\n'
using namespace std;
using i32=int;
using i64=long long;
#define int long long
typedef pair<int,int> PII;

const int N=100;
vector<int> pre(N+1,0);
vector<int> mid(N+1,0);
vector<PII> tree(N,{0,0});
int find(int l1,int r1,int l2,int r2){
    if(l1>r1||l2>r2) return 0;
    int root=pre[l1];
    int k=l2;
    while(mid[k]!=root){
        k++;
    }
    int cnt=r1-k;
    tree[root].first=find(l1+1,l1+k-l2,l2,k-1);
    tree[root].second=find(l1+k-l2+1,r1,k+1,r2);
    return root;
}

vector<int> res;
void bfs(int root){
    queue<PII> q;
    res.push_back(root);
    q.push(tree[root]);
    while(!q.empty()){
        auto t=q.front();
        q.pop();
        if(t.second!=0) res.push_back(t.second);
        if(t.first!=0) res.push_back(t.first);
        if(t.second!=0) q.push(tree[t.second]);
        if(t.first!=0) q.push(tree[t.first]);
    }
}

void solve(){
    int n;
    cin>>n;
    foe(i,0,n) cin>>mid[i];
    foe(i,0,n) cin>>pre[i];
    int root=find(0,n,0,n);
    bfs(root);
    foe(i,0,res.size()){
        if(i!=0) cout<<' ';
        cout<<res[i];
    }
    cout<<endl;
}

i32 main(){
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}