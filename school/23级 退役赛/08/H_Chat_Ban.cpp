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
#define double long double
#define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;
typedef vector<int> arr;
typedef pair<int,int> PII;

const i32 N=0;

void solve(){
    int k,x;
    cin>>k>>x;
    // 计算所有消息的总表情数
    int total=k*k;

    // 如果可以发送所有消息而不被禁
    if(x>=total){
        cout<<2*k-1<<endl;
        return;
    }
    double a1=1,b1=1,c1=-2.0*x;
    double a2=2.0,b2=-k,c2=(k*k+k)-2.0*x;
    double d1=b1*b1-4*a1*c1;
    double d2=b2*b2-4*a2*c2;

    int res1=0,res2=0;
    // 1 ~ k
    if(d1>0||fabs(d1)<1e-6){
        double x1=(-b1+sqrt(d1))/(2*a1);
        double x2=(-b1-sqrt(d1))/(2*a1);
        if(x1>0) res1=ceil(x1);
        if(x2>0) res1=ceil(x2);
    }
    // k+1 ~ 2*k-1
    if(d2>0||fabs(d2)<1e-6){
        double x1=(-b2+sqrt(d2))/(2*a2);
        double x2=(-b2-sqrt(d2))/(2*a2);
        if(x1>0) res2=ceil(x1);
        if(x2>0) res2=ceil(x2);
    }
    int res=0;
    if(res1<=k&&res1>=1){
        res=res1;
    }
    if(res2>=k&&res2<=2*k-1){
        res=res2;
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

