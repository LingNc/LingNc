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

void solve(){
    int n,k;
    cin>>n>>k;
    deque<int> q1,q2;
    vector<int> ans1,ans2,a(n,0);
    foe(i,0,n-1) cin>>a[i];
    foe(i,0,n-1){
        //找最小
        if(!q1.empty()&&q1.front()+k<=i) q1.pop_front();
        while(!q1.empty()&&a[q1.back()]>a[i]) q1.pop_back();
        q1.push_back(i);
        if(i>=k-1) ans1.push_back(a[q1.front()]);
        //找最大
        if(!q2.empty()&&q2.front()+k<=i) q2.pop_front();
        while(!q2.empty()&&a[q2.back()]<a[i]) q2.pop_back();
        q2.push_back(i);
        if(i>=k-1) ans2.push_back(a[q2.front()]);
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