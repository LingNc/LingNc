#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
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
typedef pair<int,int> PII;
int dis(PII a,PII b){
    i64 x1=a.first,y1=a.second,x2=b.first,y2=b.second;
    i64 res=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    return res;
}
void solve(){
    int n;
    cin>>n;
    vector<PII> a(n,{ 0,0 });
    foe(i,0,n-1){
        cin>>a[i].first>>a[i].second;
    }
    int a1,a2,b1,b2;
    cin>>a1>>b1>>a2>>b2;
    PII p1={ a1,b1 },p2={ a2,b2 };
    bool res=true;
    int ans=dis(p1,p2);
    foe(i,0,n-1){
        int t=dis(a[i],p2);
        if(t<=ans){
            res=false;
            break;
        }
    }
    if(res) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}