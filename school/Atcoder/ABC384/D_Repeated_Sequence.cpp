#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){return b==0?a:gcd(b,a%b);}
template<typename iii> iii lcm(iii a,iii b){return a/gcd(a,b)*b;}
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define yes(res) cout<<((res)?"YES":"NO")<<'\n'
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
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
    int N,S;
    cin>>N>>S;
    arr a(N+1,0);
    foe(i,1,N) cin>>a[i];

    // 计算前缀和
    arr preSum(N+1,0);
    int AllSum=0;
    foe(i,1,N){
        preSum[i]=preSum[i-1]+a[i];
        AllSum+=a[i];
    }

    // 计算后缀和
    arr sufSum(N+1,0);
    fod(i,N,1){
        sufSum[i]=sufSum[i+1]+a[i];
    }

    bool res=false;
    if(AllSum==0){
        if(S==0) res=true;
    }
    else{
        // 判断前缀和与后缀和的组合是否满足条件
        unordered_set<int> preSumSet(preSum.begin()+1, preSum.end()); // 前缀和去重
        unordered_set<int> sufSumSet(sufSum.begin()+1, sufSum.end()); // 后缀和去重

        for(auto &pre : preSumSet){
            if((S-pre)%AllSum==0){
                res = true;
                break;
            }
        }
    }
    yes(res);
}

i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}