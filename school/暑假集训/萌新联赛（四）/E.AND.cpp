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
    //l和r必须一个小于数组第一个下表 一个大于数组最后一个下标
    i64 l=-1,r=cnt;
    while(l+1<r){
        i64 mid=l+r>>1;
        //r为满足条件的第一个数
        if(primes[mid]>=x) r=mid;
        //l为不满足条件的最后一个数
        else l=mid;
    }
    ll=r;
    l=-1,r=cnt;
    while(l+1<r){
        i64 mid=l+r>>1;
        if(primes[mid]>y) r=mid;
        else l=mid;
    }
    rr=r;
    int num=rr-ll;
    cout<<num<<' ';
    if(x>2) cout<<0<<endl;
    else cout<<max(0,num-2)<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    get_primes(N);
    cin>>T;
    while(T--) solve();
    return 0;
}