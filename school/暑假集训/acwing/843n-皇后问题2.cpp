#include<iostream>
#include<algorithm>
#define ll long long 
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

const int N=10;
int n;
char map[N][N];
bool row[N],col[N],dg[N],udg[N];
void dfs(int x,int y){
    if(x==n&&y<n) y++,x=0;
    if(x==n&&y==n){
        foe(i,0,n-1) puts(map[i]);
        return;
    }
    //no set
    dfs(x+1,y);

    //set
    if(!row[y]&&!col[x]&&!dg[x+y]&&!udg[n+y-x]){
        map[y][x]='Q';
        row[y]=col[x]=dg[x+y]=udg[n+y-x]=true;
        dfs(0,y+1);
        map[y][x]='.';
        row[y]=col[x]=dg[x+y]=udg[n+y-x]=false;
    }
}
int main(){
    cin>>n;
    foe(i,0,n-1)foe(j,0,n-1){
        map[i][j]='.';
    }
    dfs(0,0);
    return 0;
}