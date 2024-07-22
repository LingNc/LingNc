#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long 
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

const int N=1e6+10;

int h[N],e[N],ne[N],idx=0;
bool st[N];
int ans=N,n;


//链表初始化
void init(){
    memset(h,-1,sizeof(h));
    idx=0;
}
//添加到a头指针
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx;
    idx++;
}
//输出链表
void pout(int i,int head){
    int p=head;
    cout<<i<<": ";
    while(p!=-1){
        cout<<e[p]<<' ';
        p=ne[p];
    }
    cout<<endl;
}

int dfs(int u){
    //u结点已经走过
    st[u]=true;

    int res=0,sum=1;
    for(int p=h[u];p!=-1;p=ne[p]){
        //指针指向的结点值
        int j=e[p];
        if(!st[j]){//结点没有被走过
            int s=dfs(j);
            sum+=s;
            //找最大的结果
            res=max(res,s);
        }
    }
    //树访问进来的那一部分的结点数量为n-sum
    res=max(res,n-sum);
    //总答案的最小值
    ans=min(ans,res);
    return sum;
}


int main(){
    //重复定义找了好久无语了
    //int n;
    cin>>n;
    int a,b;
    //初始化链表
    init();
    foe(i,1,n-1){
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    // foe(i,1,n-1){
        
    //     pout(i,h[i]);
    // }
    //从第一个节点开始
    dfs(1);
    cout<<ans<<endl;
    return 0;
}

//样例
/*
9
1 2
1 7
1 4
2 8
2 5
4 3
3 9
4 6
答案4
*/