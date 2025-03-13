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

const i32 N=0;

bool cmp(PII &a,PII &b){
    return a.second<b.second;
}

void solve(){
    int n;
    cin>>n;
    // arr a(2*n+1,0);
    int ZERO=n;
    vector<PII> a(n,{ 0,0 });
    int temp;
    foe(i,0,n){
        cin>>temp;
        a[i].first=temp;
        a[i].second=i;
    }
    sort(all(a),greater<PII>());
    int res=0;
    for(int i=1,k=0;k<n;i++){
        res+=i*a[k].first;
        a[k].first=-i;
        k++;
        if(k>=n) break;
        res+=i*a[k].first;
        a[k].first=i;
        k++;
    }
    sort(all(a),cmp);
    cout<<res*2<<endl;
    cout<<0<<' ';
    foe(i,0,n){
        cout<<a[i].first;
        if(i!=n-1) cout<<' ';
    }
    cout<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}