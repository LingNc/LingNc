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
 
int bfs(){
    q[0]={X0,Y0};
    g[X0][Y0]='.';
    a--;
    memset(d,-1,sizeof(d));
    d[X0][Y0]=0;
    hh=0,tt=0;
    int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
    int x,y;
    while(hh<=tt){
        auto t=q[hh++];
        foe(i,0,3){
            x=t.first+dx[i],y=t.second+dy[i];
            if(x>=0&&x<n && y>=0&&y<m &&(g[x][y]=='.'||g[x][y]=='*')&&d[x][y]==-1){
                q[++tt]={x,y};
                d[x][y]=d[t.first][t.second]+1;
                pri(d);
                if(g[x][y]=='*'){
                    a--;
                    int l=d[x][y];
                    q[0]={x,y};
                    hh=0,tt=0;
                    memset(d,-1,sizeof(d));
                    d[x][y]=l;
                    pri(d);
                    if(a==0) return d[x][y];
                    g[x][y]='.';
                    break;
                }
            }
        }
    }
    return -1;
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