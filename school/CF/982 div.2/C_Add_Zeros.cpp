#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
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

int bigger(vector<PII> &b,int len){
    int l=-1,r=b.size();
    while(l+1<r){
        int mid=(l+r)>>1;
        if(b[mid].first>len+1) r=mid;
        else l=mid;
    }
    return l;
}
int lesser(vector<PII> &b,int len){
    int l=-1,r=b.size();
    while(l+1<r){
        int mid=(l+r)>>1;
        if(b[mid].first>=len+1) r=mid;
        else l=mid;
    }
    return r;
}

int dfs(vector<PII> &b,int len){
    int l=lesser(b,len);
    int r=bigger(b,len);
    int t=0,max_len=len;
    foe(i,l,r){
        t=b[i].second-1;
        if(t==0){
            max_len=max(max_len,len);
            continue;
        }
        max_len=max(max_len,dfs(b,len+t));
    }
    return max_len;
}

void solve(){
    int n;
    cin>>n;
    arr a(n,0);
    int len=a.size();
    vector<PII> b(n,{ 0,0 });
    foe(i,0,n-1){
        cin>>a[i];
        b[i]={ a[i]+i+1,i+1 };
    }
    stable_sort(all(b));
    // int t=1;
    // while(t){
    //     int l=lesser(b,len);
    //     int r=bigger(b,len);
    //     t=0;
    //     foe(i,l,r){
    //         // if(b[i].first==len+1)
    //             t=max(t,b[i].second-1);
    //     }
    //     len+=t;
    // }
    cout<<dfs(b,len)<<endl;
}

i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}