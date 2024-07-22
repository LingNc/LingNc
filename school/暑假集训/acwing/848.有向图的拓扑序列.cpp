#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;
//记得改1e5+10
const int N=1e5+10;

//链表
int h[N],e[2*N],ne[2*N],idx;
// 队列
int q[N],st[N];
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
//打印
void pri(int i,int head){
    cout<<i<<": ";
    int p=head;
    while(p!=-1){
        cout<<e[p]<<' ';
        p=ne[p];
    }
    cout<<endl;
}
void bfs(){
    int hh=0,tt=0;
    foe(i,1,n){
        if(in[i]==0){
            q[++tt]=i;
        }
    }

    while(hh<=tt){
        int t=q[hh++];
        st[t]=true;
        for(int p=h[t];p!=-1;p=ne[p]){
            int j=e[p];
            if(!st[j]){
                q[++tt]=j;
            }
        }
    }
    if(q[n-1]==0){
        cout<<-1<<endl;
    }
    else{
        foe(i,1,n){
            cout<<q[i]<<' ';
        }
        cout<<endl;
    }
}
int main(){
    cin>>n>>m;
    int a,b;
    init();
    foe(i,1,m){
        cin>>a>>b;
        add(a,b);
    }
    foe(i,1,n){
        pri(i,h[i]);
    }
    bfs();
    return 0;
}
/*
3 3
1 2
2 3
1 3
*/
