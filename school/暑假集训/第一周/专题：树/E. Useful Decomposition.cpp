#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define long long
using i64=long long;
using namespace std;

const int N=1e5+10;
int h[N],e[2*N],ne[2*N],idx;
int n;
vector<pair<int,int>> ans;

void init(){
    memset(h,-1,sizeof h);
    idx=0;
}
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
bool dfs(int start,int u,int val,int fa){
    int cnt=0;
    bool res=true;
    if(!u) ans.clear();
    for(int p=h[val];p!=-1;p=ne[p]){
        int j=e[p];
        if(j!=fa){
            cnt++;
            res=dfs(start,u+1,j,val);
        }
    }
    if(cnt==0){
        ans.push_back({start,val});
    }
    if(!u&&res){
        cout<<"Yes"<<endl;
        cout<<ans.size()<<endl;
        for(auto &i:ans) cout<<i.first<<' '<<i.second<<endl;
    }
    if(cnt>1&&u) res=false;
    return res;
}
signed main(){
    scanf("%d",&n);
    init();
    int a,b;
    foe(i,1,n-1){
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    foe(i,1,n){
        if(dfs(i,0,1,0)) return 0;
    }
    cout<<"No"<<endl;
    return 0;
}