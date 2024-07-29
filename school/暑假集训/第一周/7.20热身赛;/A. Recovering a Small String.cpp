#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define long long
using i64=long long;
using namespace std;

const int N=1e5+10;

void solve(){
    int n;
    cin>>n;
    string res;
    for(int i=1;i<=26;i++){
        for(int j=1;j<=n-i-1&&j<=26;j++){
            int k=n-i-j;
            if(k>26) continue;
            res.push_back(i-1+'a');
            res.push_back(j-1+'a');
            res.push_back(k-1+'a');
            cout<<res<<endl;
            return;
        }
    }
}
signed main(){
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}