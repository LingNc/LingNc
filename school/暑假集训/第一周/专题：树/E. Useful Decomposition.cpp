#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define int long long
using i64=long long;
using namespace std;

const int N=1e5+10;
i64 h[N],e[2*N],ne[2*N],idx;
i64 n;
bool st[N];
void init(){
    memset(h,-1,sizeof h);
    idx=0;
}
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
double lis_len(int val,int fa){
    double l=0;
    for(int p=h[val];p!=-1;p=ne[p]){
        if(e[p]!=fa) l+=1;
    }
    return l;
}
// void pri(){
//     foe(i,1,n){
//         cout<<i<<": ";
//         for(int p=h[i];p!=-1;p=ne[p]){
//             cout<<e[p]<<' ';
//         }
//         cout<<endl;
//     }
//     cout<<endl;
// }

//u路数，pro概率
bool dfs(int val,int fa){
    int times=0;
    for(int p=h[val];p!=-1;p=ne[p]){
        if(++times>1) return false;
        int j=e[p];
        if(j!=fa)
            return dfs(j,val);
    }
    return true;
}
signed main(){
    scanf("%lld",&n);
    init();
    int a,b;
    foe(i,1,n-1){
        scanf("%lld%lld",&a,&b);
        add(a,b);
        add(b,a);
    }
    dfs(1,0);
    printf("%.7lf",res);
    return 0;
}