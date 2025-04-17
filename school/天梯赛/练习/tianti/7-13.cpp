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
vector<int> set_size(N,0);
void init(int n){
    foe(i,1,n+1){
        fa[i]=i;
    }
}

int find(int x){
    return (fa[x]!=x)?fa[x]=find(x):x;
}

void join(int x,int y){
    int fa_x=find(x);
    int fa_y=find(y);
    set_size[fa_y]+=set_size[fa_x];
    fa[fa_x]=find[fa_y];
}

void solve(){
    int n;
    cin>>n;
    init(n);
    
    int t;
    foe(i,0,n){
        cin>>t;
        cin.get();
        int the_k;
        cin>>the_k;
        set_size[find(the_k)]++;
        int a;
        foe(j,1,t){
            cin>>a;
            join(a,find(the_k));
        }
    }        
    unordered_map<int,int> mp;
}

i32 main(){
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}