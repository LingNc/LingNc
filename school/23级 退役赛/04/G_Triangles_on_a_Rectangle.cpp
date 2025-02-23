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
#define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;
typedef vector<int> arr;
typedef pair<int,int> PII;

const i32 N=0;

int max_num(){
    int num,l,r,temp;
    cin>>num;
    foe(i,0,num){
        cin>>temp;
        if(i==0) l=temp;
        if(i==num-1) r=temp;
    }
    return r-l;
}
void solve(){
    int w,h;
    cin>>w>>h;
    int down=max_num(),up=max_num();
    int left=max_num(),right=max_num();
    int max_w=max(down,up);
    int max_h=max(left,right);
    int res=max(h*max_w,w*max_h);
    cout<<res<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}