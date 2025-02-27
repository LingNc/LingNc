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
    if(n==1){
        cin>>n;
        cout<<n<<endl;
        return;
    }
    vector<int> a(n,0);
    foe(i,0,n) cin>>a[i];
    map<int,int> mp;
    foe(i,0,n-1){
        if(a[i]==a[i+1]||i<n-2&&a[i]==a[i+2]) mp[a[i]]++;
    }
    int num=0;
    for(auto &it:mp){
        if(it.second>=1){
            if(num==0) cout<<it.first;
            else cout<<' '<<it.first;
            num++;
        }
    }
    if(num==0) cout<<-1;
    cout<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}