#include<bits/stdc++.h>
#define int long long 
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
//距离第k少的国家的国家有几个城市
using namespace std;
const int N=1e5+10;
int n,m;
//much[1010];
vector<int> much;
int g[1010][1010];

void solve(){
    int q;
    cin>>n>>m>>q;
    int num;
    foe(i,1,n){
        cin>>num;
        much.push_back(num);
    }
    int u,v;
    foe(i,1,m){
        cin>>u>>v;
        g[u][v]=g[v][u]=1;
    }
    sort(much.begin(),much.end());
    int k;
    foe(i,1,q){
        cin>>k;
        cout<<much[k-1]<<endl;
    }
    
}

signed main(){
    IOS;
    int T=1;
    //cin>>T;
    while(1){
        solve();
    }
    return 0;
}