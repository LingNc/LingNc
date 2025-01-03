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
typedef struct Combine{
    //N最大，p模
    int N,p;
    vector<int> inv,fac;
    //N 最大数量，p取模的模数
    Combine(int _N,int _p):inv(_N,0),fac(_N,0){N=_N,p=_p;}
    //快速幂    
    int quickPow(int a,int b){
        int ans=1;
        while(b){
            if(b&1)
                ans=(ans*a)%p;
            b>>=1;
            a=(a*a)%p;
        }
        return ans;
    }
    //初始化
    void init(){
        fac[0]=1;
        for(int i=1;i<N;i++){
            fac[i]=fac[i-1]*i%p;
        }
        inv[N-1]=quickPow(fac[N-1],p-2);
        for(int i=N-2;i>=0;i--){
            inv[i]=inv[i+1]*(i+1)%p;
        }
    }
    //逆元求组合数 m中选n个
    int com(int m,int n){
        if(n>m) return 0;
        if(n==0) return 1;
        return fac[m]*inv[n]%p*inv[m-n]%p;
    }
    //卢斯卡定理 当p小于m时用
    int lucas(int m,int n){
        if(n==0) return 1;
        return lucas(m/p,n/p)*com(m%p,n%p)%p;
    }
    //求组合数
    int C(int m,int n){
        if(p>m) return lucas(m,n);
        else return com(m,n);
    }
}combine;

const int N=2e5+10,p=1e9+7;
combine C(N,p);

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
        res=(res+(C.C(B,i)*C.C(n-B,k-i))%p)%p;
    }
    cout<<res%p<<endl;
}
i32 main(){
    IOS;
    int T=1;
    cin>>T;
    C.init();
    while(T--) solve();
    return 0;
}