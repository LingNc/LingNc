#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define int long long
using i64=long long;
using namespace std;

const int N=1e5+10;

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> num;
    int s;
    foe(i,1,n){
        cin>>s;
        num.push_back({ s,i });
    }
    sort(num.begin(),num.end(),greater<pair<int,int>>());
    int k;
    foe(i,0,n-1){
        k=num[i].second;
        if((k-1)%2==0||(n-k)%2==0){
            cout<<num[i].first<<endl;
            return ;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}