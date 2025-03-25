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

const int N=1e7;
vector<int> is_prime;
vector<int> primes;

void sieve(){
    is_prime.resize(N+1,true);
    is_prime[0]=is_prime[1]=false;

    for(int i=2; i*i<=N; i++) {
        if(is_prime[i]) {
            for(int j=i*i; j<=N; j+=i) {
                is_prime[j]=false;
            }
        }
    }
    for(int i=2; i<=N; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
        }
    }
}

void solve(){
    int n;
    cin>>n;
    int nums=0;
    for(auto &p:primes){
        if(p>n) break;
        nums+=n/p;
    }
    cout<<nums<<endl;
}

i32 main(){
    IOS;
    sieve();
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}
