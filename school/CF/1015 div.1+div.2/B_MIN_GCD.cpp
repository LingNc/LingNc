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

void solve(){
    int n;
    cin>>n;
    arr a(n,0);
    int min_num=INF64;
    foe(i,0,n){
        cin>>a[i];
        min_num=min(min_num,a[i]);
    }
    int min_nums=1;
    arr res;
    foe(i,0,n){
        if(a[i]==min_num&&min_nums){
            min_nums--;
            continue;
        }
        if(a[i]%min_num==0){
            res.push_back(a[i]);
        }
    }
    int gcd_num=-1;
    for(auto i:res){
        if(gcd_num==-1) gcd_num=i;
        else gcd_num=gcd(gcd_num,i);
    }
    if(gcd_num==min_num){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}