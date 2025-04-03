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

const int MOD=998244353;
const int MAX_N=1e6+5;

vector<i64> fact(MAX_N),inv_fact(MAX_N);

void factorials(){
    fact[0]=1;
    for(int i=1;i<MAX_N;++i){
        fact[i]=fact[i-1]*i%MOD;
    }

    inv_fact[MAX_N-1]=1;
    i64 power=fact[MAX_N-1];
    int exp=MOD-2;
    while(exp){
        if(exp&1){
            inv_fact[MAX_N-1]=inv_fact[MAX_N-1]*power%MOD;
        }
        power=power*power%MOD;
        exp>>=1;
    }

    for(int i=MAX_N-2;i>=0;--i){
        inv_fact[i]=inv_fact[i+1]*(i+1)%MOD;
    }
}

void solve(){
    arr c(26);
    foe(i,0,26){
        cin>>c[i];
    }
    int n=0;
    for(int cnt:c){
        n+=cnt;
    }

    if(n==0){
        cout<<1<<endl;
        return;
    }

    int odd=(n+1)/2;
    int even=n/2;

    if(odd>=MAX_N){
        cout<<0<<endl;
        return;
    }

    vector<i64> dp(odd+1,0);
    dp[0]=1;

    for(int cnt:c){
        if(cnt==0) continue;
        for(int j=odd;j>=cnt;--j){
            dp[j]=(dp[j]+dp[j-cnt])%MOD;
        }
    }

    i64 product=1;
    for(int cnt:c){
        if(cnt>0){
            product=product*inv_fact[cnt]%MOD;
        }
    }

    i64 total=dp[odd]*fact[odd]%MOD;
    total=total*fact[even]%MOD;
    total=total*product%MOD;

    cout<<total<<endl;
}

i32 main(){
    IOS;
    factorials();
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}