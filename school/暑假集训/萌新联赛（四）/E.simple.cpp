#include<bits/stdc++.h>
#define lll long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define all(a) a.begin(),a.end()

using namespace std;
using i32=signed;
using i64=long long;

int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
int lcm(int a,int b){ return a/gcd(a,b)*b; }


const int N=1e8+10;
// primes[]存储所有素数
vector<int> primes;     
// st[x]存储x是否被筛掉
bool st[N];         

void get_primes(vector<int> &primes,int n){
    for(int i=2; i<=n; i++){
        if(!st[i]) primes.push_back(i);
        for(int j=0; primes[j]<=n/i; j++){
            st[primes[j]*i]=true;
            if(i%primes[j]==0) break;
        }
    }
}
void solve(){
    int x,y;
    cin>>x>>y;
    int ll=lower_bound(all(primes),x)-primes.begin();
    int rr=upper_bound(all(primes),y)-primes.begin();
    if(x<=2) cout<<rr-ll<<' '<<max(0,rr-ll-2)<<endl;
    else cout<<rr-ll<<' '<<0<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    get_primes(primes,N);
    cin>>T;
    while(T--) solve();
    return 0;
}