#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(ll i=a;i<=b;i++)
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1)foe(j,a2,b2)
using namespace std;
#include "primap.h"
int main(){
    int n,cap;
    cin>>n>>cap;
    vector<int> wgt(n+1,0),val(n+1,0);
    foe(i,1,n)
        cin>>wgt[i]>>val[i];
    vector<vector<int>> dp(n+1,vector<int>(cap+1,0));
    foee(i,1,n,c,1,cap){
        if(wgt[i]>c) dp[i][c]=dp[i-1][c];
        else dp[i][c]=max(dp[i-1][c],dp[i][c-wgt[i]]+val[i]);
        primap(dp);
    }
    cout<<dp[n][cap];
    return 0;
}
/*
in
3 4
1 5
2 11
3 15
out
22
*/