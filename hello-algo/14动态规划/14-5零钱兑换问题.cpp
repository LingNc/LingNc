#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(ll i=a;i<=b;i++)
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1)foe(j,a2,b2)

using namespace std;
//给定n种硬币，第i种硬币的面值为coins[i-1]，目标金额为amt，
//每种硬币可以重复选取，问能够凑出目标金额的最少硬币数量。
//如果无法凑出目标金额，则返回-1。示例如图 14-24 所示。
#include"primap.h"
int main(){
    int n,amt;
    cin>>n>>amt;
    vector<ll> coins(n+1,0);
    foe(i,1,n) cin>>coins[i];
    vector<vector<ll>> dp(n+1,vector<ll>(amt+1,0));
    ll max=amt+1;
    foe(a,1,amt)
        dp[0][a]=max;
    foee(i,1,n,a,1,amt)
        dp[i][a]=min(dp[i-1][a],dp[i][a-coins[i]]+1);
    cout<<((dp[n][amt]==max)?-1:dp[n][amt])<<endl;
    return 0;
}
/*
in
3 4
1 2 5
*/