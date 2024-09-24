#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(b);i>=(b);i--)
#define INF64 0x3f3f3f3f3f3f3f3f
#define INF32 0x3f3f3f3f
#define all(a) a.begin(),a.end()
#define int long long
#define endl '\n'
using namespace std;
using i32=signed;
using i64=long long;

typedef vector<int> arr;
typedef pair<int,int> PII;


void solve(){
    int n;
    cin>>n;
    arr b(500,0);
    int num,res=0;
    foe(i,1,n){
        cin>>num;
        if(num<0){
            b[-num]--;
            if(b[-num]==0) res++;
        }
        else{
            b[num]++;
            if(b[num]==0) res++;
        }
    }
    cout<<res<<endl;
}

i32 main(){
    IOS;
    int T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}