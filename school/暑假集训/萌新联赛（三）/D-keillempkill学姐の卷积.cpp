#include<bits/stdc++.h>
#define int long long 
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)

using i32=signed;
using namespace std;

const i32 N=1e2+10;
int n,m;
i32 c[N][N],g[N][N],ans[N][N];
i32 opt(i32 x,i32 y){
    int res=0;
    foe(i,0,n-1)foe(j,0,n-1){
        res+=c[i][j]*g[i+x][j+y];
    }
    return res;
}
void solve(){
    cin>>n>>m;
    foe(i,0,n-1)foe(j,0,n-1)
        cin>>c[i][j];
    foe(i,0,m-1)foe(j,0,m-1)
        cin>>g[i][j];
    foe(i,0,m-n){
        foe(j,0,m-n){
            cout<<opt(i,j)<<' ';
        }
        cout<<endl;
    }
}

i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}