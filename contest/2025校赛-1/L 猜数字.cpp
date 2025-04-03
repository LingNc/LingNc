#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){return b==0?a:gcd(b,a%b);}
template<typename iii> iii lcm(iii a,iii b){return a/gcd(a,b)*b;}
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define yes(res) cout<<((res)?"YES":"NO")<<'\n'
#define foe(i,a,b) for(int i=(a);i<(b);i++)
#define fod(i,a,b) for(int i=(a);i>(b);i--)
#define all(a) a.begin(),a.end()
#define INF64 0x3f3f3f3f3f3f3f3f
#define INF32 0x3f3f3f3f
#define int long long
// #define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;
typedef vector<int> arr;
typedef pair<int,int> PII;

const i32 N=0;


bool qes(int num){
    cout<<num<<endl;
    cout.flush();
    string res;
    cin>>res;
    return res==">=";
}

void solve(){
    int n;
    cin>>n;
    int l=1,r=n+1,mid=0;
    while(l+1<r){
        mid=(l+r)>>1;
        if(qes(mid)){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    cout<<"! "<<l<<endl;
}
i32 main(){
    // IOS;
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}