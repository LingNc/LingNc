#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){return b==0?a:gcd(b,a%b);}
template<typename iii> iii lcm(iii a,iii b){return a/gcd(a,b)*b;}
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
    int m=n/3;
    int n_mod=n%3;
    int m_mod=m%3;
    int a=m,b=m,c=m;
    if(n_mod==0){
        if(m_mod==0){
            a+=2,b-=1,c-=1;
        }
    }
    else if(n_mod==1){
        if(m_mod==0){
            a+=1,b-=1,c+=1;
        }
        else if(m_mod==1){
            a+=1;
        }
        else{
            a+=2,c-=1;
        }
    }
    else{
        if(m_mod==0){
            a+=2,b+=1,c-=1;
        }
        else if(m_mod==1){
            a+=1,b+=1;
        }
        else{
            a+=2;
        }
    }
    if(a>b) swap(a,b);
    if(b>c) swap(b,c);
    if(a>b) swap(a,b);
    cout<<a<<' '<<b<<' '<<c<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}