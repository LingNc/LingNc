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

typedef pair<int,int> PII;

const int N=1e8+10;
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
    int x,y;
    cin>>x>>y;
    int ll,rr;
    int l=0,r=cnt;
    int mid=0;
    while(l<r){
        int mid=l+r>>1;
        if(primes[mid]>x) r=mid;
        else l=mid+1;
    }
    ll=l;
    l=0,r=cnt;
    while(l<r){
        int mid=l+r>>1;
        if(primes[mid]>y) r=mid;
        else l=mid+1;
    }
    rr=l;
    int num=rr-ll+1;
    cout<<num<<' ';
    if(x>2) cout<<0<<endl;
    else{
        cout<<num-2<<endl;
    }
}
i32 main(){
    IOS;
    i32 T=1;
    get_primes(N);
    cin>>T;
    while(T--) solve();
    return 0;
}