#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define all(a) a.begin(),a.end()

using namespace std;
using i32=signed;
using i64=long long;

int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
int lcm(int a,int b){ return a/gcd(a,b)*b; }

typedef pair<int,int> PII;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n,0);
    foe(i,0,n-1) cin>>a[i];
    sort(all(a));

    int res=INT_MAX;
    foe(i,1,n-1){
        res=min(a[i]^a[i-1],res);
    }
    cout<<(int)pow(2,m)-1-res<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}