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

const i32 N=1e9+10;

int n,k;
int f(int x){
    return k*(2*x-n)+x*x-x+(n-n*n)/2;
}
int ch(int x){
    int res=k*(2*x-n)+x*x-x+(n-n*n)/2;
    if(res>0) return 1;
    else if(res<0) return -1;
    else return 0;
}
void solve(){
    cin>>n>>k;
    int l=0,r=n;
    while(l+1<r){
        int mid=l+(r-l>>1);
        if(ch(mid)*ch(l)<=0) r=mid;
        else l=mid;
    }
    cout<<min(abs(f(l)),abs(f(r)))<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}