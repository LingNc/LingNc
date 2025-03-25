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
    arr a(n,0),res(n,0);
    bool ans=true;
    unordered_map<int,int> mp;
    foe(i,0,n){
        a[i]=i+1;
        res[i]=(2*i)%n+1;
        mp[res[i]]++;
        if(mp[res[i]]>1) ans=false;
    }
    if(ans){
        foe(i,0,n){
            if(i==0) cout<<res[i];
            else cout<<' '<<res[i];
        }
        cout<<endl;
    }
    else
        cout<<-1<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}