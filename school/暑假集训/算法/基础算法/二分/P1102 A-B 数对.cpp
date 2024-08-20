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
typedef vector<int> arr;

const i32 N=0;

int bigger(arr &a,int val){
    int l=-1,r=a.size();
    while(l+1<r){
        int mid=l+(r-l>>1);
        if(a[mid]>=val) r=mid;
        else l=mid;
    }
    return (a[r]==val)?r-1:0;
}
int lesser(arr &a,int val){
    int l=-1,r=a.size();
    while(l+1<r){
        int mid=l+(r-l>>1);
        if(a[mid]<=val) l=mid;
        else r=mid;
    }
    return (a[l]==val)?l:0;
}
void solve(){
    int N,C;
    cin>>N>>C;
    arr a(N,0);
    int res=0;
    foe(i,0,N-1) cin>>a[i];
    sort(all(a));
    foe(i,0,N-1){
        int t=C+a[i];
        res+=lesser(a,t)-bigger(a,t);
    }
    cout<<res<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}