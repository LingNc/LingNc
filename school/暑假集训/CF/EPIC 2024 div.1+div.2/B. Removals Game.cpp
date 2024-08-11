#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
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

const i32 N=0;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n,0),b(n,0);
    int x;
    foe(i,0,n-1) cin>>a[i];
    foe(i,0,n-1) cin>>b[i];
    bool res=false;
    foe(i,0,(n-1)/2){
        int cnt=0;
        if(a[i]==b[i]||a[i]==b[n-i]) cnt++;
        if(a[n-i]==b[i]||a[n-i]==b[n-i]) cnt++;
        if(cnt!=2){
            res=true;
            break;
        }
    }
    if(res) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}