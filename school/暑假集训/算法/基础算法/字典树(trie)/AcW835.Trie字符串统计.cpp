#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){return b==0?a:gcd(b,a%b);}
template<typename iii> iii lcm(iii a,iii b){return a/gcd(a,b)*b;}
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define all(a) a.begin(),a.end()
#define INF64 0x3f3f3f3f3f3f3f3f
#define INF32 0x3f3f3f3f
#define ll long long
#define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;

const i32 N=1e6+10;
//字符字典树
int nex[N][26],idx=0;
//以某个字符结尾的数量
int cnt[N];

//字典树插入
void insert(string str){
    int p=0;
    for(auto &it:str){
        int temp=it-'a';
        if(!nex[p][temp]) nex[p][temp]=++idx;
        p=nex[p][temp];
    }
    cnt[p]++;
}
//字典树查询个数
int qfind(string str){
    int p=0;
    for(auto &it:str){
        int temp=it-'a';
        if(!nex[p][temp]) return 0;
        p=nex[p][temp];
    }
    return cnt[p];
}


void solve(){
    char opt;
    cin>>opt;
    string str;
    cin>>str;
    if(opt=='I') insert(str);
    else cout<<qfind(str)<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}