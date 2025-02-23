#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define yes(res) cout<<((res)?"YES":"NO")<<'\n'
#define foe(i,a,b) for(int i=(a);i<(b);i++)
#define fod(i,a,b) for(int i=(a);i>(b);i--)
#define all(a) a.begin(),a.end()
#define INF64 0x3f3f3f3f3f3f3f3f
#define INF32 0x3f3f3f3f
#define int long long
#define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;
typedef vector<int> arr;
typedef pair<int,int> PII;

const i32 N=0;

void solve(){
    int n;
    cin>>n;
    arr p(n+1,0),q(n+1,0);
    foe(i,0,n) cin>>p[i];
    string str;
    cin>>str;
    priority_queue<PII> bett,less;
    foe(i,0,str.size()){
        auto &it=str[i];
        if(it=='1') bett.push({ p[i],i });
        else less.push({ p[i],i });
    }
    int k=n;
    while(bett.empty()!=true){
        auto t=bett.top();
        bett.pop();
        q[t.second]=k--;
    }
    while(less.empty()!=true){
        auto t=less.top();
        less.pop();
        q[t.second]=k--;
    }
    foe(i,0,n){
        if(i==0) cout<<q[i];
        else cout<<' '<<q[i];
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