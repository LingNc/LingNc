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

bool check(arr &a,int h,int m){
    int res=0;
    for(auto &it:a){
        res+=max((int)0,it-h);
    }
    return (res>=m)?true:false;
}

int mfind(arr &a,int m){
    int maxa=-1;
    for(auto &i:a)
        maxa=max(i,maxa);
    int l=-1,r=maxa+1;
    while(l+1<r){
        int mid=l+(r-l>>1);
        if(check(a,mid,m)) l=mid;
        else r=mid;
    }
    return l;
}

void solve(){
    int N,M;
    cin>>N>>M;
    arr a(N,0);
    foe(i,0,N-1) cin>>a[i];
    cout<<mfind(a,M)<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}