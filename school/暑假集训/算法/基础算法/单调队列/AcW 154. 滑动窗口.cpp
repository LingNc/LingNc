#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){return b==0?a:gcd(b,a%b);}
template<typename iii> iii lcm(iii a,iii b){return a/gcd(a,b)*b;}
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define all(a) a.begin(),a.end()
#define INF64 0x3f3f3f3f3f3f3f3f
#define INF32 0x3f3f3f3f
#define ll long long
#define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;

const i32 N=1e6+10;
int q1[N],q2[N];
void solve(){
    int n,k;
    cin>>n>>k;
    int hh1=0,hh2=0,tt1=0,tt2=0;
    vector<int> ans1,ans2,a(n,0);
    foe(i,0,n-1) cin>>a[i];
    foe(i,0,n-1){
        while(tt1>hh1&&q1[hh1]+k<=i) hh1++;
        while(tt1>hh1&&a[q1[tt1-1]]>a[i]) tt1--;
        q1[tt1++]=i;
        if(i>=k-1) ans1.push_back(a[q1[hh1]]);
        
        while(tt2>hh2&&q2[hh2]+k<=i) hh2++;
        while(tt2>hh2&&a[q2[tt2-1]]<a[i]) tt2--;
        q2[tt2++]=i;
        if(i>=k-1) ans2.push_back(a[q2[hh2]]);
    }
    for(auto &i:ans1) cout<<i<<' ';
    cout<<endl;
    for(auto &i:ans2) cout<<i<<' ';
    cout<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}