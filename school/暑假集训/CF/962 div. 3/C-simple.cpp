#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
using i64=long long;
using namespace std;

void solve(){
    int n,q;
    cin>>n>>q;
    string a,b;
    cin>>a>>b;
    vector<array<int,26>> pre(n+1);
    foe(i,1,n){
        pre[i]=pre[i-1];
        pre[i][a[i-1]-'a']++;
        pre[i][b[i-1]-'a']--;
    }
    int k1,k2,sum;
    foe(i,1,q){
        cin>>k1>>k2;
        sum=0;
        foe(j,0,25){
            sum+=max(0,pre[k2][j]-pre[k1-1][j]);
        }
        cout<<sum<<endl;
    }
}

signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}