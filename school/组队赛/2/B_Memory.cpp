#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){return b==0?a:gcd(b,a%b);}
template<typename iii> iii lcm(iii a,iii b){return a/gcd(a,b)*b;}
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define yes(res) cout<<((res)?"YES":"NO")<<'\n'
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define all(a) a.begin(),a.end()
#define INF64 0x3f3f3f3f3f3f3f3f
#define INF32 0x3f3f3f3f
// #define int long long
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
    arr b(n+40,0);
    int num,site;
    foe(i,0,n-1){
        cin>>num;

        int t=(int)log2(abs(num));
        num%=2;

        site=i+t+1;
        b[site]+=num;
         if(b[site]>1){
            b[site+1]+=1;
            b[site]=0;
        }
        // if(b[site]<0){
        //     b[site+1]-=1;
        //     b[site]+=2;
        // }
    }
    // bool flag=0;
    // foe(i,1,n+36){
    //     if(b[i]<0){
    //         b[i+1]-=1;
    //         b[i]+=2;
    //     }
    //     if(b[i]!=0) flag=1;
    // }
    // if(b[n+37]<0) cout<<
    foe(i,0,n) cout<<b[i]<<' ';
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}