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
    int res=0;
    unordered_map<int,int> mp;
    int n;
    cin>>n;
    int temp;
    bool ans=false;
    int num=0;
    arr a(n,0);
    foe(i,0,n) cin>>a[i];
    foe(i,0,n){
        mp[a[i]]++;
        if(mp[0]>=3&&mp[1]>=1&&mp[2]>=2&&mp[3]>=1&&mp[5]>=1){
            num=i+1;
            break;
        }
    }
    cout<<num<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}