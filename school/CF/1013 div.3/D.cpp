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

void solve(){
    i64 n,m,totalItems;
    cin>>n>>m>>totalItems;

    i64 requiredGroups=(totalItems%n==0)?totalItems/n:totalItems/n+1;
    i64 availableWindows=m-requiredGroups+1;

    if(availableWindows<=0) {
        cout<<0<<endl;
        return;
    }

    i64 result=requiredGroups/availableWindows;
    if(requiredGroups%availableWindows!=0) result++;
    cout<<result<<endl;
}

i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}
