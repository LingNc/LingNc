#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)

using namespace std;
using i32=signed;
const int N=10;
int h[N],e[N],ne[N],idx,w[N];
int n,min_w=0x3f3f3f3f3f3f3f3f;
void init(){
    memset(h,-1,sizeof h);
    idx=0;
}
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void pri(){
    foe(i,1,n){
        cout<<i<<": ";
        for(int p=h[i];p!=-1;p=ne[p]){
            cout<<e[p]<<' ';
        }
        cout<<endl;
    }
}
int dfs(int len,int val){
    int cnt=0,res=0;
    for(int p=h[val];p!=-1;p=ne[p]){
        int j=e[p];
        cnt++;
        res=min(res,dfs(len+1,j));
    }
    if(!cnt) return w[1]+w[val]-len;
    return res;
}
void solve(){
    cin>>n;
    foe(i,1,n)
        cin>>w[i];
    int fa;
    init();
    foe(i,2,n){
        cin>>fa;
        add(fa,i);
    }
    pri();
    cout<<dfs(1,1)<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}