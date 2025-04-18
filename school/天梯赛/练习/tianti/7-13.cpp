#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
// #define endl '\n'
using namespace std;
using i32=int;
using i64=long long;
#define int long long
typedef pair<int,int> PII;
#define all(a) a.begin(),a.end()


const int N=1e4;
vector<int> fa(N,0);
vector<int> set_size(N,1);
void init(int n){
    foe(i,1,n+1){
        fa[i]=i;
    }
}

int find(int x){
    return (fa[x]!=x)?fa[x]=find(fa[x]):x;
}

void join(int x,int y){
    int fa_x=find(x);
    int fa_y=find(y);
    if(fa_x==fa_y) return;
    set_size[fa_y]+=set_size[fa_x];
    fa[fa_x]=find(fa_y);
}

void solve(){
    int n;
    cin>>n;
    init(n);
    unordered_map<int,vector<int>> mp;
    int t;
    foe(i,1,n+1){
        cin>>t;
        cin.get();
        int a;
        foe(j,0,t){
            cin>>a;
            mp[a].push_back(i);
        }
    }
    for(auto &it:mp){
        int user=it.second[0];
        foe(i,1,it.second.size()){
            join(it.second[i],user);
        }
    }
    unordered_map<int,int> res;
    foe(i,1,n+1){
        int j=find(i);
        res[j]=set_size[j];
    }
    vector<int> ans;
    for(auto &it:res) ans.push_back(it.second);
    sort(all(ans),greater<int>());
    cout<<ans.size()<<endl;
    foe(i,0,ans.size()){
        if(i!=0) cout<<' ';
        cout<<ans[i];
    }
    cout<<endl;
}

i32 main(){
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}