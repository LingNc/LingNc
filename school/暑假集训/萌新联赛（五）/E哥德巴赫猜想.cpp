#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){return b==0?a:gcd(b,a%b);}
template<typename iii> iii lcm(iii a,iii b){return a/gcd(a,b)*b;}
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

const i32 N=1e5+10;
int primes[N],cnt;     // primes[]存储所有素数
bool st[N];         // st[x]存储x是否被筛掉

void get_primes(int n){
    for(int i=2; i<=n; i++){
        if(!st[i]) primes[cnt++]=i;
        for(int j=0; primes[j]<=n/i; j++){
            st[primes[j]*i]=true;
            if(i%primes[j]==0) break;
        }
    }
}
void solve(){
    int num;
    cin>>num;
    if(num<=5){
        cout<<-1<<endl;
        return ;
    }
    for(int i=0;primes[i]<num;i++){
        for(int j=i;primes[j]<num;j++){
            int res=num-primes[i]-primes[j];
            if(!st[res]&&res!=0){
                cout<<primes[i]<<' '<<primes[j]<<' '<<res<<endl;
                return ;
            }
        }
    }
}
i32 main(){
    IOS;
    get_primes(N);
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}