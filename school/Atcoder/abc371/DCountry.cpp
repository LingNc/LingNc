#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){return b==0?a:gcd(b,a%b);}
template<typename iii> iii lcm(iii a,iii b){return a/gcd(a,b)*b;}
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define yes(res) cout<<((res)?"Yes":"No")<<'\n'
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


int bigger(vector<PII> &a,int x){
    int l=0,r=a.size();
    while(l+1<r){
        int mid=l+r>>1;
        if(a[mid].first>x) r=mid;
        else l=mid;
    }
    return r;
}

void solve(){
    int N;
    cin>>N;
    vector<PII> a(N+1,{0,0});
    arr b(N+1,0);
    foe(i,1,N) cin>>a[i].first;
    foe(i,1,N) cin>>a[i].second;
    // sort(a.begin()+1,a.end());
    foe(i,1,N) b[i]=b[i-1]+a[i].second;

    int Q;
    cin>>Q;
    int l,r;
    foe(i,1,Q){
        cin>>l>>r;
        int ans_l=bigger(a,l)-1;
        int ans_r=bigger(a,r);
        int ans=b[ans_r-1]-b[ans_l-1];
        cout<<ans<<endl;
    }
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}