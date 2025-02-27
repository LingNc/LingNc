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

void prime(unordered_map<int,int> &lis,int x){
    int res=x;
    foe(i,2,x+1){
        if(res%i==0){
            while(res%i==0)
                res/=i;
            lis[i]++;
            if(res==1) break;
        }
    }
}

void solve(){
    int n;
    cin>>n;
    unordered_map<int,int> lis0,lis1;
    int temp;
    foe(i,0,n){
        cin>>temp;
        if(i%2==0) prime(lis0,temp);
        else prime(lis1,temp);
    }
    unordered_map<int,int> res0;
    int num0=n/2+1,num1=n/2;
    for(auto &it:lis0){
        if(it.second==num0)
            res0[it.first]=1;
    }
    int ans=0;
    for(auto &it:lis1){
        if(it.second==num1){
            if(res0.count(it.first)==0){
                ans=it.first;
                break;
            }
        }
    }
    cout<<ans<<endl;

}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}