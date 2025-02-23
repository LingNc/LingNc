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

const i32 n=1e3+10;
void solve(){
    int N,Q;
    cin>>N>>Q;
    vector<vector<vector<int>>> slice(3,vector<vector<int>>(n,vector<int>(n,N)));
    int x,y,z;
    int res=0;
    foe(i,0,Q){
        cin>>x>>y>>z;
        // 1 xy 2 yz 3 xz
        slice[0][x][y]--;
        if(slice[0][x][y]==0) res++;
        slice[1][y][z]--;
        if(slice[1][y][z]==0) res++;
        slice[2][x][z]--;
        if(slice[2][x][z]==0) res++;
        cout<<res<<endl;
    }
}
i32 main(){
    IOS;
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}