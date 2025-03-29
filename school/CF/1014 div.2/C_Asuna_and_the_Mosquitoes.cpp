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

const i32 N=2e5+5;
int x[N];

void solve(){
    int n;
    cin>>n;
    int even_cnt=0,odd_cnt=0,sum=0,max_val=0;
    foe(i,0,n){
        cin>>x[i];
        if(x[i]%2==0) even_cnt++;
        else odd_cnt++;
        sum+=x[i];
        max_val=max(max_val,x[i]);
    }

    if(even_cnt==0||odd_cnt==0){
        cout<<max_val<<endl;
    }
    else{
        sum=sum-odd_cnt+1;
        if(sum%2==0) cout<<sum-1<<endl;
        else cout<<sum<<endl;
    }
}

i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}