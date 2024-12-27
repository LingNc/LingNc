#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define yes(res) cout<<((res)?"Yes":"No")<<'\n'
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

// int res(vector<int> &a){
//     map<pair<int,int>,int> mp;
//     int max_length=-1;
//     if(a.size()<=1) return 1;
//     foe(i,0,(int)a.size()-2){
//         foe(j,i+1,(int)a.size()-1){
//             int dis=a[j]-a[i];
//             mp[{j,dis}]=((mp.count({ i,dis }))
//                 ?mp[{i,dis}]+1
//                 :2);
//             max_length=max(max_length,mp[{j,dis}]);
//         }
//     }
//     return max_length;
// }
int res(vector<int> &nums){
    int n=nums.size();
    unordered_map<long long,vector<int>> hash;
    for(int i=0;i<n;i++){
        hash[nums[i]].push_back(i);
    }

    int sum=0;
    vector<vector<int>> dp(n,vector<int>(n));
    for(int j=2;j<n;j++){
        for(int i=1;i<j;i++){
            long long a=(long long)2*nums[i]-nums[j];
            if(hash.count(a)){
                for(auto e:hash[a]){
                    if(e<i){ dp[i][j]+=dp[e][i]+1; }
                    else break;
                }
            }
            sum+=dp[i][j];
        }
    }
    return sum;
}

void solve(){
    size_t N;
    cin>>N;
    unordered_map<int,vector<int>> mp;
    int num;
    foe(i,1,N){
        cin>>num;
        mp[num].push_back(i);
    }
    int max_res=-1;
    for(auto &it:mp){
        auto &a=it.second;
        max_res=max(max_res,res(a));
    }
    cout<<max_res<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}