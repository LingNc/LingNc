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

    // dp[i][j][last] 表示前i天选了j天出去吃饭，第i天状态为last的方案数
    // last=0表示吃外卖，last=1~m表示去对应地点吃饭
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(m+1,0)));

    // 初始条件：第0天，没有选择任何天出去吃饭
    dp[0][0][0]=1;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=min(i,k); j++){
            // 第i天吃外卖
            for(int last=0; last<=m; last++){
                dp[i][j][0]+=dp[i-1][j][last];
            }

            // 第i天去某个地点吃饭
            if(j>0){
                for(int curr=1; curr<=m; curr++){
                    for(int last=0; last<=m; last++){
                        // 若前一天也去了同一地点，则不合法
                        if(last!=curr||last==0){
                            dp[i][j][curr]+=dp[i-1][j-1][last];
                        }
                    }
                }
            }
        }
    }

    int res=0;
    // 最终答案：第n天，选了k天出去吃饭
    if(k==0){
        res=dp[n][0][0]; // 如果k=0，只能全吃外卖
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