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

// const i32 N=0;
//高精度加法
string add(string &a,string &b){
    if(a.size()<b.size()) return add(b,a);
    string res;
    reverse(all(a));reverse(all(b));
    int t=0;
    foe(i,0,a.size()-1){
        t+=a[i]-'0';
        if(i<b.size()) t+=b[i]-'0';
        res.push_back(t%10+'0');
        t/=10;
    }
    if(t) res.push_back(t+'0');
    reverse(all(res));
    return res;
}

void solve(){
    string a,b;
    cin>>a>>b;
    cout<<add(a,b)<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}