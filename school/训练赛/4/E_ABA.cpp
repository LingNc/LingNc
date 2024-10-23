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
    unordered_map<char,vector<int>> mp;
    string S;
    cin>>S;
    foe(i,0,S.size()-1){
        mp[S[i]].push_back(i+1);
    }
    int res=0;
    for(auto &it:mp){
        auto a=it.second;
        if(a.size()<2) continue;
        arr b(a);
        int sum=0,n=a.size()-1;
        fod(i,n,1){
            if(i==n) continue;
            b[i]+=b[i+1];
        }
        foe(i,0,n-1){
            res+=b[i+1]-(n-i)*(a[i]+1);
        }
    }
    cout<<res<<endl;
}

i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}