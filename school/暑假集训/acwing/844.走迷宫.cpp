#include<iostream>
#include<algorithm>
#include<cstring>
#include<utility>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

const int N=110;

int n,m;
int map[N][N];
int d[N][N];

//模拟队列
typedef pair<int,int> Pr;
Pr q[N*N];


int bfs(){
    int head=0,tail=0;
    q[0]={0,0};
    memset(d,-1,sizeof(d));
    d[0][0]=0;

    int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
    while(head<=tail){
        auto t=q[head++];
        foe(i,0,3){
            int x=t.first+dx[i],y=t.second+dy[i];
            if(x>=0&&x<n&&y>=0&&y<m&&map[x][y]==0&&d[x][y]==-1){
                d[x][y]=d[t.first][t.second]+1;
                q[++tail]={x,y};
            }
        }
    }
    return d[n-1][m-1];
}
int main(){
    cin>>n>>m;
    foe(i,0,n-1)
        foe(j,0,m-1){
        cin>>map[i][j];
    }
    cout<<bfs()<<endl;
    return 0;
}