#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define all(a) a.begin(),a.end()
#define INF64 0x3f3f3f3f3f3f3f3f
#define INF32 0x3f3f3f3f
#define int long long
// #define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;
typedef vector<int> arr;
typedef pair<int,int> PII;

const i32 N=1e6+10;

bool query(int m){
    cout<<"? "<<m<<" "<<m<<endl;
    int res,ans=m*m;
    cin>>res;
    return (res==ans)?0:1;
}

int bigger(){
    int l=0,r=1000;
    while(l+1<r){
        int mid=l+(r-l>>1);
        if(query(mid)) r=mid;
        else l=mid;
    }
    return r;
}
void solve(){
    int res=bigger();
    cout<<"! "<<res<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}