#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define yes(res) cout<<((res)?"YES":"NO")<<'\n'
#define foe(i,a,b) for(int i=(a);i<(b);i++)
#define fod(i,a,b) for(int i=(a);i>(b);i--)
#define aint(a) a.begin(),a.end()
#define INF64 0x3f3f3f3f3f3f3f3f
#define INF32 0x3f3f3f3f
#define int long long
#define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;
typedef vector<int> arr;
typedef pair<int,int> PII;


void solve(){
    int n,k;
    int x;
    cin>>n>>k>>x;
    arr a(n);
    foe(i,0,n){
        cin>>a[i];
    }
    arr pre(n+1,0);
    foe(i,0,n){
        pre[i+1]=pre[i]+a[i];
    }
    int total=pre[n];

    int res=0;
    if(total<=0){
        int r=0;
        int sum=0;
        foe(l,0,n){
            if(r<l){
                r=l;
                sum=0;
            }
            while(r<n&&sum+a[r]<x){
                sum+=a[r];
                ++r;
            }
            if(r<n&&sum+a[r]>=x){
                res+=k;
            }
            sum-=a[l];
        }
    }
    else{
        int r=0;
        int sum=0;
        foe(l,0,n){
            if(r<l){
                r=l;
                sum=0;
            }
            while(r<n&&sum+a[r]<x){
                sum+=a[r];
                ++r;
            }
            if(r<n&&sum+a[r]>=x){
                res+=k;
                sum-=a[l];
                continue;
            }
            int rem=x-sum;
            int m=(rem+total-1)/total;
            if(m<k){
                res+=k-m;
            }
            sum-=a[l];
        }
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