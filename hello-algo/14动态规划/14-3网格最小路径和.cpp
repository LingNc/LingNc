/*
Question
给定一个 n×m 的二维网格 grid ，网格中的每个单元格包含一个非负整数，
表示该单元格的代价。机器人以左上角单元格为起始点，每次只能向下或者向右移动一步，
直至到达右下角单元格。请返回从左上角到右下角的最小路径和。
*/
#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1) foe(j,a2,b2)
#define endl '\n'

using namespace std;
int min_grid(vector<vector<int>> &grid);
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n+1,vector<int>(m+1));
    foee(i,1,n,j,1,m)
        cin>>grid[i][j];
    cout<<min_grid(grid)<<endl;
    return 0;
}
int min_grid(vector<vector<int>> &grid){
    int n=grid.size()-1;
    int m=grid[0].size()-1;
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    foee(i,1,n,j,1,m){
            if(i==1)
                dp[i][j]=dp[i][j-1];
            else if(j==1)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=min(dp[i][j-1],dp[i-1][j]);
            dp[i][j]+=grid[i][j];
        }
    return dp[n][m];
}