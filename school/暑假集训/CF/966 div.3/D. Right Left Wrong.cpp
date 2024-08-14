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
#define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;

const i32 N=0;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1,0),b(n+1,0);
    foe(i,1,n) cin>>a[i];
    vector<char> str(n+1,0);
    foe(i,1,n){
        cin>>str[i];
        b[i]=b[i-1]+a[i];
    }
    int res=0,l=1,r=n;
    while(1){
        while(str[l]!='L'&&l<=n) l++;
        while(str[r]!='R'&&r>=1) r--;
        if(r<l) break;
        res+=b[r]-b[l-1];
        l++,r--;
    }
    cout<<res<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}