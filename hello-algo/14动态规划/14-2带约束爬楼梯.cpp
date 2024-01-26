//给定一个共有 n 阶的楼梯，你每步可以上 1 阶或者 2 阶，
//但不能连续两轮跳 1 阶，请问有多少种方案可以爬到楼顶？
#include<iostream>
#include<algorithm>
#include<vector>
#define endl '\n'
using namespace std;
int climb_dp(int n);
int main(){
    int n;
    cin>>n;
    cout<<climb_dp(n)<<endl;
    return 0;
}
int climb_dp(int n){
    vector<vector<int>> dp(n+1,vector<int>(3,0));
    dp[1][1]=dp[2][2]=1;
    for(int i=3;i<=n;i++){
        dp[i][1]=dp[i-1][2];
        dp[i][2]=dp[i-2][1]+dp[i-2][2];
    }
    return dp[n][1]+dp[n][2];
}