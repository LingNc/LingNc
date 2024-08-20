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
double a,b,c,d;
double f(double x){
    return a*pow(x,3)+b*pow(x,2)+c*x+d;
}
double root(double x1,double x2){
    while(x2-x1>0.0001){
        double mid=(x1+x2)/2.0;
        if(f(mid)*f(x1)<=0) x2=mid;
        else x1=mid;
    }
    return x1;
}
void solve(){
    cin>>a>>b>>c>>d;
    foe(i,-100,100){
        if(f(i)*f(i+1)<0||f(i)==0) cout<<fixed<<setprecision(2)<<root(i,i+1)<<' ';
    }
}
i32 main(){
    //IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}