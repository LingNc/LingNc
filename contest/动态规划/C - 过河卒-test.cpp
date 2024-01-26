#include<iostream>
#include<algorithm>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1)foe(j,a2,b2)
#include<cstring>
using namespace std;

int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    int dp[21][21]={ 0 };
    dp[0][0]=1;
    //horse点
    dp[x][y]=2;
    dp[x-1][y-2]=dp[x-1][y+2]=2;
    dp[x-2][y-1]=dp[x-2][y+1]=2;
    dp[x+1][y-2]=dp[x+1][y+2]=2;
    dp[x+2][y-1]=dp[x+2][y+1]=2;
    foee(i,0,n,j,0,m){
        if(dp[i][j]==2){
            dp[i][j]=0;
            continue;
        }
        if(i==0&&j!=0)
            dp[i][j]=dp[i][j-1];
        if(i!=0&&j==0)
            dp[i][j]=dp[i-1][j];
        if(i!=0&&j!=0)
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        foee(a1,0,n,a2,0,m){
            cout<<dp[a1][a2]<<' ';
            if(a2==n) putchar(endl);
        }
        putchar(endl);
    }
    cout<<dp[n][m]<<endl;
    return 0;
}