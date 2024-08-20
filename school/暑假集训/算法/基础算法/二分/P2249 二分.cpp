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
const i32 N=0;
int qfind(vector<int> &a,int x){
    int l=-1,r=a.size();
    while(l+1<r){
        int mid=(l+r)>>1;
        if(a[mid]>=x) r=mid;
        else l=mid;
    }
    if(a[r]==x) return r+1;
    else return -1;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n,0);
    foe(i,0,n-1) cin>>a[i];
    int q;
    foe(i,1,m){
        cin>>q;
        cout<<qfind(a,q)<<' ';
    }
    cout<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}