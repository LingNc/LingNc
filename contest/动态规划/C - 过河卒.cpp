#include<iostream>
#include<algorithm>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(ll i=a;i<=b;i++)
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1)foe(j,a2,b2)
using namespace std;

int main(){
    ll n,m,x,y;
    cin>>n>>m>>x>>y;
    ll dp[40][40]={ 0 };
    dp[1][0]=1;
    n++,m++,x++,y++;
    foee(i,1,n,j,1,m){
        ll ix=abs(i-x),jy=abs(j-y);
        if(ix<=2&&jy<=2&&ix+jy==3||ix==0&&jy==0){
            dp[i][j]=0;
            continue;
        }
        dp[i][j]=dp[i-1][j]+dp[i][j-1];
    }
    cout<<dp[n][m]<<endl;
    return 0;
}