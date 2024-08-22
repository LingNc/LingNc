
#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){return b==0?a:gcd(b,a%b);}
template<typename iii> iii lcm(iii a,iii b){return a/gcd(a,b)*b;}
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define all(a) a.begin(),a.end()
#define INF64 0x3f3f3f3f3f3f3f3f
#define INF32 0x3f3f3f3f
// #define int long long
// #define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;
typedef vector<int> arr;
typedef pair<int,int> PII;

const i32 N=0;

int query(int a,int b){
    cout<<"? "<<a<<' '<<b<<endl;
    int ans,res1=a*b,res3=(a+1)*(b+1);
    cin>>ans;
    if(ans==res1) return 1;
    else if(ans==res3) return 3;
    else return 2;
}

int three(){
    int l=0,r=1000;
    while(l+1<r){
        int m=max((int)3,r-l);
        int midl=l+m/3,midr=r-m/3;
        int t=query(midl,midr);
        if(t==1) l=midr;
        else if(t==3) r=midl;
        else l=midl,r=midr;
    }
    return r;
}
void solve(){
    int res=three();
    cout<<"! "<<res<<endl;
}

i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}