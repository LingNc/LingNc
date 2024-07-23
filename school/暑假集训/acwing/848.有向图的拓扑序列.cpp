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

//打印h
void print(int i,int head){
    cout<<i<<": ";
    int p=head;
    while(p!=-1){
        cout<<e[p]<<' ';
        p=ne[p];
    }
    cout<<endl;
}
//打印邻接表数据
void pri(){
    foe(i,1,n){
        print(i,h[i]);
    }
}

//添加邻接表
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
    in[b]++;
}
//删除单向边a，b之间
void remove(int a,int b){
    if(e[h[a]]==b){
        h[a]=ne[h[a]];
    }
    else{
        for(int p=h[a];p!=-1;p=ne[p]){
            if(e[ne[p]]==b){
                ne[p]=ne[ne[p]];
            }
        }
    }
    //修改入度
    in[b]--;
}
//删除a结点
void del(int a){
    for(int p=h[a];p!=-1;p=h[a]){
        in[e[p]]--; 
        h[a]=ne[h[a]];
    }
}
//初始化
void init(){
    memset(h,-1,sizeof(h));
    idx=0;
}

void bfs(){
    int hh=0,tt=0;
    foe(i,1,n){
        if(in[i]==0){
            q[tt++]=i;
        }
    }
    //pri();
    while(hh<=tt){
        int t=q[hh++];
        for(int p=h[t];p!=-1;p=ne[p]){
            int j=e[p];
            remove(t,j);
            //pri();
            if(!in[j]){
                q[tt++]=j;
            }
        }
    }
    if(q[n-1]==0){
        cout<<-1<<endl;
    }
    else{
        foe(i,0,n-1){
            cout<<q[i]<<' ';
        }
        cout<<endl;
    }
}
signed main(){
    cin>>n>>m;
    int a,b;
    init();
    foe(i,1,m){
        cin>>a>>b;
        add(a,b);
    }
    // pri();
    bfs();
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