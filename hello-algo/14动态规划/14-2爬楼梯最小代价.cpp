//给定一个楼梯，你每步可以上 1 阶或者 2 阶，
//每一阶楼梯上都贴有一个非负整数，表示你在该台阶所需要付出的代价。
//给定一个非负整数数组 cost ，其中 cost[i] 表示在第 i 个台阶需要付出的代价，
//cost[0] 为地面（起始点）。
//请计算最少需要付出多少代价才能到达顶爬楼梯最小代价
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int climb_dp(vector<int> &cost);
int main(){
    int n;
    cin>>n;
    vector<int> cost(n+1);
    for(int i=1;i<=n;i++){
        cin>>cost[i];
    }
    cout<<climb_dp(cost)<<'\n';
    return 0;
}
int climb_dp(vector<int> &cost){
    int n=cost.size();
    vector<int> dp(n);
    dp[1]=cost[1],dp[2]=cost[2];
    for(int i=3;i<=n;i++){
        dp[i]=min(dp[i-1],dp[i-2])+cost[i];
    }
    return dp[n];
}