#include<iostream>
#include<algorithm>
#include<utility>
#include<cstring>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;


const int N=3;
int n;
char M[N][N];
int d[N][N];

//模拟队列
typedef struct {
    pair<int,int> p;
    char g[N][N];
    int d[N][N];
}PII;
PII q[100000000],last;

template<typename T> void pri_M(T M[N][N]){
    foe(i,0,N-1){
        foe(j,0,N-1){
            cout<<M[i][j]<<' ';
        }
        cout<<endl;
    }
}
int bfs(int x0,int y0){
    int head=0,tail=0;
    q[0].p={x0,y0};
    int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
    memset(d,-1,sizeof(d));
    memmem(q[0].d,-1,sizeof(q[0].d));
    q[0].d[x0][y0]=0;
    d[x0][y0]=0;
    while(head<=tail){

        auto t=q[head++];
        int x=t.p.first,y=t.p.second;
        bool flag=0;
        if(x==N-1&&y==N-1){
            char *ptr=&t.g[0][0];
            int sum=0;
            foe(i,0,7){
                if(*(ptr+i)==i+1+'0'){
                    sum++;
                }
            }
            if(sum==8)
                flag=1;
        }
        if(flag) return d[N-1][N-1];
        foe(i,0,3){
            x=t.p.first+dx[i],y=t.p.second+dy[i];
            if(x>=0&&x<3&&y>=0&&y<3&&(t.p.first!=x||t.p.second!=y)){
                q[++tail].p={x,y};
                foe(i,0,N-1)foe(j,0,N-1){
                    q[tail].g[i][j]=t.g[i][j];
                }
                char m=q[tail].g[x][y];
                q[tail].g[x][y]=q[tail].g[t.p.first][t.p.second];
                q[tail].g[t.p.first][t.p.second]=m;
                
                foe(i,0,N-1)foe(j,0,N-1){
                    q[tail].d[i][j]=t.d[i][j];
                }
                q[tail].d[x][y]=q[tail].d[t.p.first][t.p.second]+1;
            }
        }
        last=t;
        pri_M(t.g);
        cout<<endl;
        pri_M(t.d);
        cout<<endl;
    }

}

int main(){
    int x,y;
    foe(i,0,N-1)foe(j,0,N-1){
        cin>>q[0].g[i][j];
        if(q[0].g[i][j]=='x'){
            x=i,y=j;
        }
    }
    cout<<bfs(x,y)<<endl;
    return 0;
}