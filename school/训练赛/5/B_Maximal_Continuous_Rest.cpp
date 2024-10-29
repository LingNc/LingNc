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
    int n;
    cin>>n;
    arr a(3*n+1,0);
    int num;
    foe(i,1,n){
        cin>>num;
        a[i]=a[i+n]=a[i+2*n]=num;
    }
    int one=0,max_one=-1;
    foe(i,0,3*n-1){
        if(a[i]==1) one++;
        max_one=max(max_one,one);
        if(a[i]==0) one=0;
    }
    cout<<max_one<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}