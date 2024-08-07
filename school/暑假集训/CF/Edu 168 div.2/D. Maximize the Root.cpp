#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define INF 0x3f3f3f3f
using i32=signed;
using i64=long long;

using namespace std;

const int N=1e6+10;
int e[2*N],ne[2*N],h[N],idx;
int w[N];
int n;

void init(){
    //多次memset h[]超时
    foe(i,0,n) h[i]=-1;
    idx=0;
}
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

//返回子树最小值
int dfs(int val){
    //如果到头返回自己
    if(h[val]==-1) return w[val];
    int res=INF;
    for(int p=h[val];p!=-1;p=ne[p]){
        int j=e[p];
        res=min(res,dfs(j));
    }
    //如果头节点删子节点最小值删到不能再删
    if(val==1) return w[1]+res;
    //正常节点返回子节点最小值，或者让当前节点加到不超过最小值的值
    if(w[val]<res) return (w[val]+res)/2;
    else return res;
}
void solve(){
    cin>>n;
    init();
    foe(i,1,n)
        cin>>w[i];
    int fa;
    foe(i,2,n){
        cin>>fa;
        add(fa,i);
    }
    cout<<dfs(1)<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}