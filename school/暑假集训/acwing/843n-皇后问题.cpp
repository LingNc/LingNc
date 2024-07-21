#include<iostream>
#include<algorithm>
#define ll long long 
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

const int N=10;
int n;
char map[N][N];
bool col[N],dg[N],udg[N];;
void dfs(int f){
    if(f==n){
        foe(i,0,n-1){
            puts(map[i]);
        }
        cout<<endl;
        return ;
    }
    foe(i,0,n-1){
        if(!col[i]&&!dg[f+i]&&!udg[n+f-i]){
            col[i]=dg[f+i]=udg[n+f-i]=true;
            map[f][i]='Q';
            dfs(f+1);
            col[i]=dg[f+i]=udg[n+f-i]=false;
            map[f][i]='.';
        }
    }
}
int main(){
    cin>>n;
    foe(i,0,n-1)foe(j,0,n-1){
        map[i][j]='.';
    }
    dfs(0);
    return 0;
}