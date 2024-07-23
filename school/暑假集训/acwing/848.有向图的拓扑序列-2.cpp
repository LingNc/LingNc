#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#define int long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;
//记得改1e5+10
const int N=1e5+10;

//链表
int h[N],e[2*N],ne[2*N],idx;
// 队列
int q[N];
int n,m,in[N];

//添加邻接表
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
    in[b]++;
}
//初始化
void init(){
    memset(h,-1,sizeof(h));
    idx=0;
}

bool topsort(){
    int hh=0,tt=-1;
    foe(i,1,n)
        if(in[i]==0) q[++tt]=i;

    while(hh<=tt){
        int t=q[hh++];
        for(int p=h[t];p!=-1;p=ne[p]){
            int j=e[p];
            in[j]--;
            if(!in[j])
                q[++tt]=j;
        }
    }
    return (q[n-1]==0)?false:true;
}
signed main(){
    cin>>n>>m;
    int a,b;
    //初始化
    init();
    foe(i,1,m){
        cin>>a>>b;
        add(a,b);
    }
    if(topsort())
        foe(i,0,n-1) cout<<q[i]<<' ';
    else
        cout<<-1<<endl;
    return 0;
}
/*
3 3
1 2
2 3
1 3

1 2 3
*/
/*
4 4
2 1
1 3
1 4
3 4

2 1 3 4
*/
/*
3 2
1 3
2 3

3
*/
