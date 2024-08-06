#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define ai64(a) a.begin(),a.end()

using namespace std;
using i32=signed;
using i64=long long;
int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
int lcm(int a,int b){ return a/gcd(a,b)*b; }

const int N=2e5+10,p=1e9+7;
int qmi(int a,int k,int p);
int C(int a,int b,int p);
void solve(){
    int n,k,B=0;
    cin>>n>>k;
    bool num=0;
    foe(i,1,n){
        cin>>num;
        if(num) B++;
    }
    i64 res=0;
    foe(i,k/2+1,k){
        res=(res+(C(B,i,p)*C(n-B,k-i,p))%p)%p;
    }
    cout<<res%p<<endl;
}
i32 main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}
// 快速幂模板
int qmi(int a,int k,int p){
    int res=1%p;
    while(k){
        if(k&1)
            res=(i64)res*a%p;
        a=(i64)a*a%p;
        k>>=1;
    }
    return res;
}
// 通过定理求组合数C(a, b)
int C(int a,int b,int p){
    if(a<b) return 0;

    i64 x=1,y=1;  // x是分子，y是分母
    for(int i=a,j=1; j<=b; i--,j++){
        x=(i64)x*i%p;
        y=(i64)y*j%p;
    }

    return x*(i64)qmi(y,p-2,p)%p;
}
