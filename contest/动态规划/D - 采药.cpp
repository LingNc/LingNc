#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(ll i=a;i<=b;i++)
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1)foe(j,a2,b2)
using namespace std;
int main(){
    int T,M;
    cin>>T>>M;
    vector<int> time(M+1,0),val(M+1,0);
    foe(i,1,M){
        cin>>time[i]>>val[i];
    }
    vector<vector<int>> dp(M+1,vector<int>(T+1,0));
    foee(i,1,M,t,1,T){
        if(time[i]>t) dp[i][t]=dp[i-1][t];
        else dp[i][t]=max(dp[i-1][t],dp[i-1][t-time[i]]+val[i]);
    }
    cout<<dp[M][T]<<endl;
    return 0;
}
