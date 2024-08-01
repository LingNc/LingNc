#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define INF 0x3f3f3f3f

using namespace std;
using i32=signed;
using i64=long long;
const int N=1e6+10;
int e[2*N],ne[2*N],h[N],idx;
int w[N],ans[N];
int n;

void init(int nn){
    foe(i,0,2*nn){
        e[i]=ne[i]=0;
    }
    foe(i,0,nn){
        w[i]=ans[i]=0;
        h[i]=-1;
    }
    idx=0;
}
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

//返回子树最小值
void dfs(int val){
    //如果到头返回自己
    if(h[val]==-1){
        ans[val]=w[val];
        return;
    }
    int res=INF;
    for(int p=h[val];p!=-1;p=ne[p]){
        int j=e[p];
        dfs(j);
        res=min(res,ans[j]);
    }
    //如果头节点删子节点最小值删到不能再删
    if(val==1){
        ans[1]=w[1]+res;
        return;
    }
    //正常节点返回子节点最小值，或者让当前节点加到不超过最小值的值
    if(w[val]<res) ans[val]=(w[val]+res)/2;
    else ans[val]=res;
}
void solve(){
    cin>>n;
    init(n);
    foe(i,1,n)
        cin>>w[i];
    int fa;
    foe(i,2,n){
        cin>>fa;
        add(fa,i);
    }
    dfs(1);
    cout<<ans[1]<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}