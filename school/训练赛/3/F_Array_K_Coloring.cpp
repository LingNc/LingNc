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
    int n,k;
    cin>>n>>k;
    unordered_map<int,int> mp,mp0;
    arr a(n+1,0),use(k+1,0);
    foe(i,1,n){
        cin>>a[i];
        mp[a[i]]++;
        mp0[a[i]]=1;
    }
    for(auto &it:mp){
        if(it.second>k){
            yes(0);
            return;
        }
    }
    yes(1);
    int res;
    int k0=0;
    for(auto &it:mp){
        if(k0<k){
            mp0[it.first]=
            k0+=it.second;
        }
        else{

        }
    }
    foe(i,1,n){
        int num=1;
        res=mp0[a[i]]++;
        use[res]=1;
        cout<<res<<' ';
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