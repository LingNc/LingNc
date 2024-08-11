#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

// ----------------------------------------------------------------------------
// 2024-08-10
// The code below was written solely by Waaaaaaaaaaa. Please do not plagiarize. Thank you.
// ----------------------------------------------------------------------------

const int maxn=0;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n,0),b(n,0);
    int x;
    for(int i=0;i<=n-1;i++) cin>>a[i];
    for(int i=0;i<=n-1;i++) cin>>b[i];
    bool res=false;
    for(int i=0;i<=(n-1)/2;i++){
        int cnt=0;
        if(a[i]==b[i]||a[i]==b[n-i]) cnt++;
        if(a[n-i]==b[i]||a[n-i]==b[n-i]) cnt++;
        if(cnt!=2){
            res=true;
            break;
        }
    }
    if(res) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
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