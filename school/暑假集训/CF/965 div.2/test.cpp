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
    vector<int> a(n+1,0),b(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]+1<=n){
            cout<<a[i]+1<<" ";
        }
        else{
            cout<<1<<" ";
        }
    }
    cout<<endl;
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