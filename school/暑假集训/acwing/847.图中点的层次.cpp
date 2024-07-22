#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long 
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;
//记得改1e5+10
const int N=1e5+10;
// 链表
int h[N],e[2*N],ne[2*N],idx,head;
//队列
int q[N],hh,tt;
int n,m,dis[N],st[N];

//初始化
void init(){
    memset(h,-1,sizeof(h));
    idx=0;
}
//头插
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
//打印
// void pri(int i,int head){
//     int p=head;
//     cout<<i<<": ";
//     while(p!=-1){
//         cout<<e[p]<<' ';
//         p=ne[p];
//     }
//     cout<<endl;
// }

int bfs(){
    memset(dis,-1,sizeof(dis));
    q[0]=1;
    dis[1]=0;
    hh=tt=0;

    while(hh<=tt){
        int t=q[hh++];
        //这里为什么不可以
        //if(t==n) return dis[t];
        for(int p=h[t];p!=-1;p=ne[p]){
            int j=e[p];
            if(dis[j]==-1&&!st[j]){
                st[j]=true;
                dis[j]=dis[t]+1;
                q[++tt]=j;
            }
        }
    }
    //不是找不到就输出-1怎么不需要
    //return -1;
    return dis[n];
}

int main(){
    cin>>n>>m;
    int a,b;
    //初始化链表
    init();
    foe(i,1,m){
        cin>>a>>b;
        add(a,b);
    }
    // foe(i,1,n){
    //     pri(i,h[i]);
    // }
    cout<<bfs()<<endl;
    return 0;
}
/*
4 5
1 2
2 3
3 4
1 3
1 4
*/
