#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define all(a) a.begin(),a.end()
#define INF64 0x3f3f3f3f3f3f3f3f
#define INF32 0x3f3f3f3f
#define int long long
// #define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;
typedef vector<int> arr;

const i32 N=1e6+10;
typedef pair<int,int> PII;


vector<PII> edge;
map<int,bool> q;
int now,n;
int query(int a,int b){
    cout<<"? "<<a<<' '<<b<<endl;
    int res;
    cin>>res;
    return res;
}
void qdfs(int a,int b){
    if(a>b) swap(a,b);
    if(q.count(b)) return;
    int res=query(a,b);
    if(res==a){
        q[b]=true;
        edge.push_back({ a,b });
        return;
    }
    qdfs(a,res);
    qdfs(res,b);
}
void solve(){
    cin>>n;
    edge.clear();
    q.clear();
    int last=15*n,now=0;
    int res,a=1,b=2;
    foe(i,1,n-1){
        a=i,b=i+1;
        qdfs(a,b);
        // if(now>last) return;
    }
    cout<<'!';
    for(auto &it:edge){
        cout<<' '<<it.first<<' '<<it.second;
    }
    cout<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}