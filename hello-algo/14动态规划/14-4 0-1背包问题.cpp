/*
给定 n 个物品，第 i 个物品的重量为 wgt[i−1]、价值为 val[i−1] ，
和一个容量为 cap 的背包。每个物品只能选择一次，问在限定背包容量下能放入物品的最大价值。
*/
#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
#define endl '\n'
//单层循环
#define foe(i,a,b) for(int i=a;i<=b;i++)
//双层循环
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1) foe(j,a2,b2)
using namespace std;
int max_price(vector<int> &wgt,vector<int> &val,int cap);
int main(){
    int n,cap;
    cin>>n>>cap;
    vector<int> wgt(n+1,0);
    vector<int> val(n+1,0);
    foe(i,1,n){
        cin>>wgt[i]>>val[i];
    }
    cout<<max_price(wgt,val,cap);
    return 0;
}
int max_price(vector<int> &wgt,vector<int> &val,int cap){
    int n=wgt.size()-1;
    //前i个物品在背包剩余容量为c的情况下的最大价值dp表
    vector<vector<int>> val_dp(n+1,vector<int>(cap+1,0));
    foee(i,1,n,c,1,cap){
        if(wgt[i]>c){
            val_dp[i][c]=val_dp[i-1][c];
        }
        else
            val_dp[i][c]=max(val_dp[i-1][c],val_dp[i-1][c-wgt[i]]+val[i]);
    }
    return val_dp[n][cap];
}

/*
in
5 50
10 50
20 120
30 150
40 210
50 240
out
270
in
3 4
1 5
2 11
3 15
out
20
*/