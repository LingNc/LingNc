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

const i32 N=0;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    foe(i,1,n) cin>>a[i];
    sort(all(a));
    int l,r;
    cin>>l>>r;
    int sl=0,sr=0,sum=0;
    int numl=0,numr=0,nums=0;
    for(auto &i:a){
        if(i==0) continue;
        if(i<l) sl+=l-i,numl++;
        if(i>r) sr+=i-r,numr++;
        if(i>=l&&i<=r) sum+=r-i,nums++;
    }
    if(sl<sr){
        if(sr-sl>numl*(r-l)+sum) cout<<-1<<endl;
        else cout<<sr<<endl;
    }
    else{
        if(sl-sr>numr*(r-l)+nums*(r-l)-sum) cout<<-1<<endl;
        else cout<<sl<<endl;
    }
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}