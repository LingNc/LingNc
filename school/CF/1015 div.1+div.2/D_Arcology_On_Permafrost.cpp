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

const i32 N=0;


void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    int x=min(n/(m+1),n-m*k);

    arr a(n,x);
    arr count(x,0);
    for(int i=0; i<n&&count[a[i]%x]<m+1; i++){
        a[i]=i%x;
        count[a[i]]++;
    }
    int curr=0;
    for(int i=0; i<n; i++){
        if(a[i]==x){
            while(count[curr%x]>=m+1&&curr<x) curr++;
            a[i]=curr%x;
            count[a[i]]++;
            curr++;
        }
    }
    for(int i=0; i<n; i++){
        cout<<a[i]<<(i==n-1?'\n':' ');
    }
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}