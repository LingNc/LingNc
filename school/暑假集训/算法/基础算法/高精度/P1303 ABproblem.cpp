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

const i32 N=5e3+10;
//高精度乘法
int res[N]={0};
string mul(string &a,string &b){
    if(a.size()>b.size()) return mul(b,a);
    reverse(all(a)),reverse(all(b));
    foe(i,0,b.size()-1){
        foe(j,0,a.size()-1){
            res[i+j]+=(a[j]-'0')*(b[i]-'0');
        }
    }
    int len=a.size()+b.size();
    foe(i,0,len-1){
        res[i+1]+=res[i]/10;
        res[i]=res[i]%10;
    }
    while(!res[len-1]&&len>1) len--;
    string c;
    foe(i,0,len-1){
        c.push_back(res[i]+'0');
    }
    reverse(all(c));
    return c;
}

void solve(){
    string a,b;
    cin>>a>>b;
    cout<<mul(a,b)<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}