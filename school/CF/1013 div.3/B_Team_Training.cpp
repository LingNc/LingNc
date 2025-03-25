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
    i64 n,m,count=0;
    cin>>n>>m;
    arr nums(n);
    foe(i,0,n) cin>>nums[i];
    sort(all(nums));
    fod(i,n-1,-1){
        i64 groupSize=1,current=nums[i];
        if(current>=m){
            count++;
            continue;
        }
        bool valid=false;
        while(current<m){
            groupSize++;
            i--;
            if(i<0) break;
            current=groupSize*nums[i];
        }
        if(current>=m) count++;
    }
    cout<<count<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}