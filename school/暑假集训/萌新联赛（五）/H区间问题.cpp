#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){return b==0?a:gcd(b,a%b);}
template<typename iii> iii lcm(iii a,iii b){return a/gcd(a,b)*b;}
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
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

const i32 N=1e6+10;
int a[N],Lg[N],f[N][20];

void solve(){
    int n;
	cin>>n; 
    Lg[1]=0;
    foe(i,2,n) Lg[i]=Lg[i>>1]+1;
    foe(i,1,n) cin>>f[i][0];
    foe(j,1,Lg[n])foe(i,1,n-(1<<j)+1){
		f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	}
	int q;
    cin>>q;
	int l,r;
	foe(i,1,q){
		cin>>l>>r;
        int L=Lg[r-l+1];
		cout<<max(f[l][L],f[r-(1<<L)+1][L])<<endl;
	}
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}