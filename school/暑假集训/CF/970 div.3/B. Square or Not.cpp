#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
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

const i32 N=0;

void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    bool res=1;
    int sq=sqrt(n);
    if(sq*sq!=n) res=0;
    else{
        char flag;
        foe(i,0,sq-1){
            foe(j,0,sq-1){
                if(j==0||j==sq-1) flag='1';
                if(str[i*sq+j]!=flag){
                    res=0;
                    break;
                }
                if((j==0||j==sq-1)&&i!=0&&i!=sq-1) flag='0';
            }
            if(!res) break;
        }
    }

    if(res) yes(res);
    else yes(res);
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}