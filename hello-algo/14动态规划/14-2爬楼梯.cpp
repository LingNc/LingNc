//给定一个共有n阶的楼梯，你每步可以上1阶或者2阶，请问有多少种方案可以爬到楼顶？
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
int climb_dp(int n);
int main(){
    int n;
    cin>>n;
    cout<<climb_dp(n)<<'\n';
    return 0;
}
int climb_dp(int n){
    int dp[n+1];
    if(n==1||n==2)
        return dp[n];
    dp[1]=1,dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
