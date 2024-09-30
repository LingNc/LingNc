#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define int long long
#define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;
typedef vector<int> arr;
typedef pair<int,int> PII;

const i32 N=0;

void solve(){
    arr a(9);
    int mx=-1,mi=101;
    foe(i,0,8){
        cin>>a[i];
        mx=max(a[i],mx);
        mi=min(a[i],mi);
    }
    if(mi==mx) cout<<80<<endl;
    else  cout<<max(mx,(int)80)<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}