#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define aint(a) a.begin(),a.end()

using namespace std;
using i32=signed;
using i64=long long;

int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
int lcm(int a,int b){ return a/gcd(a,b)*b; }

const int maxn=2e6+10;
const int p=998244353;
int inv[maxn], fac[maxn];
 
int quickPow(int a,int b){
    int ans=1;
    while(b){
        if(b&1)
            ans=(ans*a)%p;
        b>>=1;
        a=(a*a)%p;
    }
    return ans;
}
 
void init(){
    fac[0]=1;
    for(int i=1;i<maxn;i++){
        fac[i]=fac[i-1]*i%p;
    }
    inv[maxn-1]=quickPow(fac[maxn-1],p-2);
    for(int i=maxn-2;i>=0;i--){
        inv[i]=inv[i+1]*(i+1)%p;
    }
}
 
int C(int n,int m){
    if(m>n) return 0;
    if(m==0) return 1;
    return fac[n]*inv[m]%p*inv[n-m]%p;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n,0);
    int sum=0;
    foe(i,0,n-1){
        cin>>a[i];
        sum+=a[i];
    }
    int res;
    res=C(m-sum+n,n);
    cout<<res<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    init();
    //cin>>T;
    while(T--) solve();
    return 0;
}