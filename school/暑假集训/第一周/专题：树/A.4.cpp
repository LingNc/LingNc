#include<bits/stdc++.h>
#define ll long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'

using i64=long long; 
using namespace std;

const int N=1e6+10;
int n,x,y;
//邻接表
int e[2*N],ne[2*N],h[N],idx;
//每个结点的子树大小包含自己
int Size[N];

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
//         cout<<Size[i]<<' ';
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
//val 当前结点值  fa 上一个结点值 返回是否包含y路径
bool dfs(int val,int fa){
    Size[val]=1;
    //pri_path(u);
    bool have_y=false;
    for(int p=h[val];p!=-1;p=ne[p]){
        int j=e[p];
        //没有走回头路
        if(j!=fa){
            bool flag=dfs(j,val);
            if(!flag) Size[val]+=Size[j];
            have_y|=flag;
        }
    }
    return (val==y||have_y)?true:false;
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
    dfs(x,0);
    i64 res=n*(n-1)-Size[x]*Size[y];
    //pri_size();
    cout<<res<<endl;
    return 0;
}