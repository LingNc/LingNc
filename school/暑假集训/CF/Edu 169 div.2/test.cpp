#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

// ----------------------------------------------------------------------------
// 2024-08-15
// The code below was written solely by Waaaaaaaaaaa. Please do not plagiarize. Thank you.
// ----------------------------------------------------------------------------


void solve(){
    int res=0,n,k;
    cin>>n>>k;
    vector<int> a(n+1,0);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.begin()+n);
    for(int i=n-1;i>=0;i--){
        res+=a[i--];
        if(i>=0){
            if(k>=a[i+1]-a[i]){
                k-=a[i+1]-a[i];
                res-=a[i+1];
            }
            else if(k>0){
                res-=a[i];
                res-=k;
                k=0;
            }
            else res-=a[i];
        }
    }
    cout<<res<<'\n';
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}