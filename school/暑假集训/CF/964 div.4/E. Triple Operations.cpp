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

const int N=2e5+10;
int a[N];
int ch(int x){
    int ans=0;
    while(x){
        ans++;
        x/=3;
    }
    return ans;
}
void solve(){
    int l,r;
    cin>>l>>r;
    int ans=a[r]-a[l-1];
    ans+=ch(l);
    cout<<ans<<endl;
    return;
}
i32 main(){
    IOS;
    a[0]=0;
    for(int i=1;i<=N-10;i++){
        a[i]=ch(i)+a[i-1];
    }
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}