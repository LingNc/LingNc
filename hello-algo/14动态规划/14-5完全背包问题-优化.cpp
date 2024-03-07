#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(ll i=a;i<=b;i++)
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1)foe(j,a2,b2)

using namespace std;

int main(){
    ll n,cap;
    cin>>n>>cap;
    vector<ll> wgt(n+1,0),val(n+1,0);
    foe(i,1,n) cin>>wgt[i]>>val[i];
    vector<ll> dp(cap+1,0);
    foee(i,1,n,c,1,cap){
        if(wgt[i]>c) dp[c]=dp[c];
        else dp[c]=max(dp[c],dp[c-wgt[i]]+val[i]);
    }
    cout<<dp[cap]<<endl;
    return 0;
}