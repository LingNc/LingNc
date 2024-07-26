#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define ll long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'

using namespace std;

const int N=1e6+10;
int n,x,y,sum=0;
//邻接表
int e[2*N],ne[2*N],h[N],idx;
bool st[N];
int path[N];


//初始化
void init(){
    memset(h,-1,sizeof(h));
    idx=0;
}
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void dfs(int u,int val,bool hx){
    if(u>1){
        // foe(i,0,u-1)
        //     cout<<path[i]<<' ';
        // cout<<endl;
        sum++;
    }

    for(int p=h[val];p!=-1;p=ne[p]){
        int j=e[p];
        if(!st[j]){
            path[u]=j;
            if(j==x){
                st[j]=true;
                dfs(u+1,j,true);
                st[j]=false;
            }
            else if(hx==false||j!=y){
                st[j]=true;
                dfs(u+1,j,hx);
                st[j]=false;
            }
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&x,&y);
    int a,b;
    init();
    foe(i,1,n-1){
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    foe(i,1,n){
        add(0,i);
    }
    dfs(0,0,false);
    cout<<sum<<endl;
    return 0;
}