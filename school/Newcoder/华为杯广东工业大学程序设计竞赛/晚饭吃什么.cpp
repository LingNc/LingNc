#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define yes(res) cout<<((res)?"YES":"NO")<<'\n'
#define foe(i,a,b) for(int i=(a);i<(b);i++)
#define fod(i,a,b) for(int i=(a);i>(b);i--)
#define all(a) a.begin(),a.end()
#define INF64 0x3f3f3f3f3f3f3f3f
#define INF32 0x3f3f3f3f
#define int long long
#define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;
typedef vector<int> arr;
typedef pair<int,int> PII;

const i32 N=0;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(m+1,0)));
    dp[0][0][0]=1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=min(i,k); j++){
            for(int last=0; last<=m; last++){
                dp[i][j][0]+=dp[i-1][j][last];
            }
            if(j>0){
                for(int curr=1; curr<=m; curr++){
                    for(int last=0; last<=m; last++){
                        if(last!=curr||last==0){
                            dp[i][j][curr]+=dp[i-1][j-1][last];
                        }
                    }
                }
            }
        }
    }

    int res=0;
    if(k==0){
        res=dp[n][0][0];
    }
    else{
        for(int last=0; last<=m; last++){
            res+=dp[n][k][last];
        }
    }

    cout<<res<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}