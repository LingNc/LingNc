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
#define int long long
#define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;
typedef vector<int> arr;
typedef pair<int,int> PII;

const i32 N=0;

void solve(){
    int l1,l2,l3;
    cin>>l1>>l2>>l3;
    bool res=false;
    if(l1==l2&&l3%2==0||l2==l3&&l1%2==0||l1==l3&&l2%2==0) res=true;
    if(l1>l2) swap(l1,l2);
    if(l2>l3) swap(l2,l3);
    if(l1>l2) swap(l1,l2);
    if(l3==l1+l2) res=true;
    yes(res);
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}