#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
using namespace std;

const int N=1e6+10;
int n,x,y;
//邻接表
int e[2*N],ne[2*N],h[N],idx;

int sz[N];
//初始化
void init(){
    memset(h,-1,sizeof(h));
    idx=0;
}
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
// void pri_size(){
//     foe(i,1,n){
//         cout<<sz[i]<<' ';
//     }
//     cout<<endl<<endl;
// }
// void pri_list(){
//     foe(i,1,n){
//         cout<<i<<": ";
//         for(int p=h[i];p!=-1;p=ne[p]){
//             cout<<e[p]<<' ';
//         }
//         cout<<endl;
//     }
//     cout<<endl;
// }

//val 当前结点值  fa 上一个结点值
//返回该节点的子树大小除去包含从y开始的子树
int dfs(int val,int fa,int yorx){
    int res=1;
    for(int p=h[val];p!=-1;p=ne[p]){
        int j=e[p];
        if(j!=fa&&j!=yorx){
            res+=dfs(j,val,yorx);
        }
    }
    //sz[val]=res;
    return res;
}
signed main(){
    IOS;
    cin>>n>>x>>y;
    int a,b;
    init();
    foe(i,1,n-1){
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    int num_x=dfs(x,0,y);
    int num_y=dfs(y,0,x);
    //pri_size();
    int size_x=n-num_y,size_y=n-num_x;
    int res=n*(n-1)-size_x*size_y;
    cout<<res<<endl;
    
    return 0;
}