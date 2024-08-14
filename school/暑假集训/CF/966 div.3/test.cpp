#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

// ----------------------------------------------------------------------------
// 2024-08-13
// The code below was written solely by Waaaaaaaaaaa. Please do not plagiarize. Thank you.
// ----------------------------------------------------------------------------


void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> b(n+2,vector<int>(m+2,0));
    priority_queue<int> q;

    for(int i=1;i<=n-k+1;i++){
        for(int j=1;j<=m-k+1;j++){
            b[i][j]++,b[i][j+k]--,b[i+k][j]--,b[i+k][j+k]++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            b[i][j]=b[i][j]+b[i-1][j]+b[i][j-1]-b[i-1][j-1];
            q.push(b[i][j]);
        }
    }
    int num,t,res=0;
    cin>>num;
    vector<int> big(num,0);
    for(int i=1;i<=num;i++) cin>>big[i-1];
    sort(big.begin(),big.end(),greater<int>());
    for(int i=1;i<=num;i++){
        res+=big[i-1]*q.top();
        q.pop();
        if(q.empty()) break;
    }
    cout<<res<<endl;
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