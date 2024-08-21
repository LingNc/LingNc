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
typedef vector<int> arr;

const i32 N=0;

typedef pair<int,int> PII;
void solve(){
    int n;
    cin>>n;
    // arr a(n,0);
    int odd=0,even=0,no=0,ne=0;
    int num;
    foe(i,0,n-1){
        cin>>num;
        if(i==0||i==n-1) continue;
        if(num%2){
            odd++;
            no+=(num+1)/2;
        }
        else{
            even++;
            ne+=num/2;
        }
    }
    if(ne>=odd) cout<<ne+no<<endl;
    else cout<<-1<<endl;

}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}