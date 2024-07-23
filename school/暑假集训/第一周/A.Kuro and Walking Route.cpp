#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

const int N=4e6+10;
int n,x,y;
//邻接表
int e[2*N],ne[2*N],h[N],idx;
bool st[N];
int path[N],ans=0;


//初始化
void init(){
    memset(h,-1,sizeof(h));
    idx=0;
}
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void dfs(int u,int f,bool hx){
    if(u>1){
        ans++;
    }
    for(int p=h[f];p!=-1;p=ne[p]){
        int j=e[p];
        if(!st[j]&&!(hx==true&&j==y)){
            path[u]=j;
            st[j]=true;
            if(j==x) hx=true;
            dfs(u+1,j,hx);
            st[j]=false;
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
        path[0]=i;
        st[i]=true;
        dfs(1,i,i==x);
        st[i]=false;
    }
    cout<<ans<<endl;
    return 0;
}