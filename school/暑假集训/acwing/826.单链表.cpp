#include<iostream>
#include<algorithm>
#define ll long long 
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

const int N=1e5+10;

int e[N],ne[N],idx,head;

//链表初始化
void init(){
    head=-1;
    idx=0;
}
//插入到头结点
void add_to_head(int x){
    e[idx]=x;
    ne[idx]=head;
    head=idx++;
}
//插入到第k个结点后面
void add(int x,int k){
    e[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx++;
}
//删除第k个插入的数后面的数
void del(int k){
    ne[k]=ne[ne[k]];
}

int main(){
    int M;
    cin>>M;
    char opt;
    int x;

    // 初始化链表
    init();
    foe(i,1,M){
        cin>>opt;
        if(opt=='H'){
            cin>>x;
            add_to_head(x);
        }
        else if(opt=='D'){
            cin>>x;
            if(!x) head=ne[head];
            del(x-1);
        }
        else if(opt=='I'){
            int k;
            cin>>k>>x;
            add(x,k-1);
        }
    }
    int p;
    p=head;
    while(p!=-1){
        cout<<e[p]<<' ';
        p=ne[p];
    }
    cout<<endl;
    return 0;
}