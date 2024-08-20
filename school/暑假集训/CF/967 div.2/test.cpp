#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

// ----------------------------------------------------------------------------
// 2024-08-20
// The code below was written solely by Waaaaaaaaaaa. Please do not plagiarize. Thank you.
// ----------------------------------------------------------------------------

void solve(){
    int n;
    cin>>n;
    if(!(n%2)) cout<<-1<<endl;
    else{
        for(int i=n;i>=1;i-=2)
            cout<<i<<' ';
        for(int i=2;i<n;i+=2)
            cout<<i<<' ';
        cout<<endl;
    }
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