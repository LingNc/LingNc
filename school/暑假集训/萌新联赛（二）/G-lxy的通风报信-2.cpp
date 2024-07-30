#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
//#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)

using namespace std;
const int N=10;
int n,m,a;
char g[N][N];
int d[N][N];
int X0,Y0;
//队列
typedef pair<int,int> PII;
PII q[N*N];
int hh,tt;

void pri(int d[N][N]){
    foe(i,0,n-1){
        foe(j,0,m-1){
            cout<<d[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}


void solve(){
    cin>>n>>m;
    foe(i,0,n-1){
        foe(j,0,m-1){
            cin>>g[i][j];
            if(g[i][j]=='*'){
                a++;
                if(a==1){
                    X0=i,Y0=j;
                }
            }
        }
    }
    cout<<bfs()<<endl;
}
signed main(){
    IOS;
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
/*
#####
#....
*..##
.#.*#
*####

*/