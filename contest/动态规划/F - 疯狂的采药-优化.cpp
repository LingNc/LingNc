#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(ll i=a;i<=b;i++)
#define fob(i,a,b) for(ll i=b;i>=a;i--)
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1)foe(j,a2,b2)

using namespace std;

int main(){
    ll T,M;
    cin>>T>>M;
    vector<ll> time(M+1,0),val(M+1,0);
    foe(i,1,M) cin>>time[i]>>val[i];
    vector<ll> dp(T+1,0);
    foee(m,1,M,t,1,T){
        if(time[m]>t) dp[t]=dp[t];
        else dp[t]=max(dp[t],dp[t-time[m]]+val[m]);
    }
    cout<<dp[T]<<endl;
    return 0;
}
