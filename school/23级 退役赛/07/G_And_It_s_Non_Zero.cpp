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
// #define int long long
#define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;
typedef vector<int> arr;
typedef pair<int,int> PII;

const i32 N=0;

int num_one(int x,int n){
    int the_num=x;
    int t=1<<(n-1);
    x-=t-1;
    int a=x%t;
    bool one=the_num&t;
    int num=x/t;
    int res=0;
    if(num%2==0){
        res+=t*(num/2);
    }
    else{
        res+=t*(num/2)+t;
    }
    if(one) res+=a;
    return res;
}

void solve(){
    int l,r;
    cin>>l>>r;
    int max_res=-1;
    foe(i,1,33){
        int tl=num_one(l-1,i);
        int tr=num_one(r,i);
        max_res=max(max_res,tr-tl);
    }
    cout<<r-l+1-max_res<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}