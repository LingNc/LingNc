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
#define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;
typedef vector<int> arr;
typedef pair<int,int> PII;

const i32 N=0;

bool cmp(PII &a,PII &b){
    return a.second<b.second;
}

void solve(){
    int n;
    cin>>n;
    vector<PII> a(n,{ 0,0 });
    foe(i,0,n){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(all(a));
    vector<PII> b=a;
    vector<PII> last;
    int p1=0,p2=0;
    int res=0;
    foe(i,0,a.size()){
        if(a[i].first>b[p1].first){
            b[p1++].first=a[i].first;
            res++;
        }
        else last.push_back(a[i]);
    }
    // foe(i,p1,b.size()){
    //     b[i].first=last[i-p1].first;
    // }
    // sort(all(b),cmp);
    cout<<res<<endl;
    // foe(i,0,b.size()){
    //     if(i==0) cout<<b[i].first;
    //     else cout<<' '<<b[i].first;
    // }
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}