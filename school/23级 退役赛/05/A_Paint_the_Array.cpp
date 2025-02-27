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
    int temp;
    vector<int> a(n,0);
    foe(i,0,n)
        cin>>a[i];
    int ngcd=0;
    for(int i=0;i<n;i+=2){
        if(ngcd==0) ngcd=a[i];
        else ngcd=gcd(ngcd,a[i]);
    }
    bool res=true;
    if(ngcd==1){
        ngcd=0;
        for(int i=1;i<n;i+=2){
            if(ngcd==0) ngcd=a[i];
            else ngcd==gcd(ngcd,a[i]);
        }
        for(int i=0;i<n;i+=2){
            if(a[i]%ngcd==0){
                res=false;
                break;
            }
        }
    }
    else{
        for(int i=1;i<n;i+=2){
            if(a[i]%ngcd==0){
                res=false;
                break;
            }
        }
    }
    if(res) cout<<ngcd<<endl;
    else cout<<res<<endl;

}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}