#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(ll i=a;i<=b;i++)
#define fob(i,a,b) for(ll i=a;i>=b;i--)
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1)foe(j,a2,b2)

using namespace std;

int main(){
    ll T,M;
    cin>>T>>M;
    vector<ll> time(M+1,0),val(M+1,0);
    foe(i,1,M) cin>>time[i]>>val[i];
    vector<vector<ll>> dp(M+1,vector<ll>(T+1,0));
    foee(m,1,M,t,1,T){
        if(time[m]>t) dp[m][t]=dp[m-1][t];
        else dp[m][t]=max(dp[m-1][t],dp[m][t-time[m]]+val[m]);
    }
    cout<<dp[M][T]<<endl;
    return 0;
}