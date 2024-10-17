#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
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

int inz_sum(int num){
    unordered_map<int,int> mp;
    vector<int> q;
    int i=2;
    while(num>1){
        if(!(num%i)){
            num/=i;
            mp[i]++;
        }
        else{
            i++;
        }
    }
    int res=1;
    for(auto &it:mp){
        int a=it.second,p=it.first;
        res*=((int)pow(p,a+1)-1)/(p-1);
    }
    return res;
}

void solve(){
    int c;
    cin>>c;
    // cout<<inz_sum(c)<<endl;
    foe(i,1,c){
        int ans=inz_sum(i);
        if(ans!=c) continue;
        else{
            // cout<<"ans:"<<ans<<endl;
            cout<<i<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}