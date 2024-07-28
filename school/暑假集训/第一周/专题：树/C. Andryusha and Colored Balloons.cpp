#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define fod(i,a,b) for(int i=a;i>=b;i--)
#define endl '\n'

using i64=long long;
using namespace std;

const int N=1e6+10;
int e[2*N],ne[2*N],h[N],idx;
int n,max_clr,clr[N];
void init(){
    memset(h,-1,sizeof h);
    idx=0;
}
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int val,int fa){
    int c=1;
    for(int p=h[val];p!=-1;p=ne[p]){
        int j=e[p];
        if(j!=fa){
            while(c==clr[val]||c==clr[fa])
                c++;
            max_clr=max(max_clr,c);
            clr[j]=c++;
            dfs(j,val);
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    init();

    cin>>n;
    int a,b;
    foe(i,1,n-1){
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    clr[1]=1;
    dfs(1,0);
    cout<<max_clr<<endl;
    foe(i,1,n){
        cout<<clr[i]<<' ';
    }
    cout<<endl;
    return 0;
}