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
    int even=0,odd=0;
    int num;
    int mo=-1,me=-1;
    foe(i,1,n){
        cin>>num;
        if(i%2){
            odd++;
            mo=max(mo,num);
        }
        else{
            even++;
            me=max(me,num);
        }
    }
    odd+=mo;even+=me;
    cout<<max(odd,even)<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}