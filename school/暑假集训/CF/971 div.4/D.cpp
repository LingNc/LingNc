#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define yes(res) cout<<((res)?"YES":"NO")<<'\n'
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
typedef pair<int,int> PII;

const i32 N=2e5+10;
int x[N][2];
int f(int k){
    int res=0;
    if(x[k][0]&&x[k+1][1]&&x[k+2][0]) res++;
    if(x[k][1]&&x[k+1][0]&&x[k+2][1]) res++;
    return res;
}
void solve(){
    int n;
    cin>>n;
    int a,b;
    memset(x,0,sizeof x);
    foe(i,1,n){
        cin>>a>>b;
        x[a][b]=1;
    }
    int res=0,t;
    int one=0,tow=0;
    foe(i,0,n){
        res+=f(i);
        t=x[i][0]+x[i][1];
        if(t==1) one++;
        else if(t==2) tow++;
    }
    res+=one*tow;
    res+=2*tow*(tow-1);
    cout<<res<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}