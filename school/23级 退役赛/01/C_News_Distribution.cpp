#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define yes(res) cout<<((res)?"YES":"NO")<<'\n'
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define all(a) a.begin(),a.end()
#define INF64 0x3f3f3f3f3f3f3f3f
#define INF32 0x3f3f3f3f
// #define int long long
// #define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;
typedef vector<int> arr;
typedef pair<int,int> PII;

const i32 N=1e6+10;

typedef struct Adj{
    int h[N],e[2*N],ne[2*N],idx;
    bool st[N];
    int w[N];
    //初始化
    void init(int n){
        foe(i,0,n) h[i]=-1, fork[i]=0, st[i]=false;
        idx=0;
        p_fork=0;
    }
    //加边
    void _add(int a,int b){
        e[idx]=b,ne[idx]=h[a],h[a]=idx++;
    }
    void add(int a,int b){
        _add(a,b);
        _add(b,a);
    }
    unordered_map<int,int> mp;
    int fork[N];
    int p_fork;
    int dfs(int node,int nums){
        for(int p=h[node];p!=-1;p=ne[p]){
            int j=e[p];
            if(st[j]) continue;
            st[j]=true;
            mp[j]=p_fork;
            nums=dfs(j,nums+1);
            st[j]=false;
        }
        return nums;
    }
    int search(int node){
        st[node] = true;
        int nums=dfs(node,1);
        fork[p_fork]=nums;
        return nums;
    }
    int get_nums(int node){
        if(mp.count(node)==0){
            p_fork++;
            return 0;
        }
        else{
            return fork[mp[node]];
        }
    }
}Adj;

void solve(){
    Adj adj;
    int n,m;
    cin>>n>>m;
    adj.init(n+10);
    int temp;
    foe(i,1,m){
        cin>>temp;
        if(temp==0) continue;
        int now,last;
        cin>>last;
        foe(j,2,temp){
            cin>>now;
            adj.add(last,now);
            last=now;
        }
    }
    foe(i,1,n){
        int nums=adj.get_nums(i);
        if(nums){
            cout<<nums<<' ';
        }
        else{
            cout<<adj.search(i)<<' ';
        }
    }
    cout<<endl;

}
i32 main(){
    IOS;
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}