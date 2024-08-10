#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){return b==0?a:gcd(b,a%b);}
template<typename iii> iii lcm(iii a,iii b){return a/gcd(a,b)*b;}
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define all(a) a.begin(),a.end()
#define INF64 0x3f3f3f3f3f3f3f3f
#define INF32 0x3f3f3f3f
#define ll long long
#define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;

const i32 N=0;

bool is_prime(int num){
    if(num<=3) return (num==1)?false:true;
    int sq=sqrt(num);
    foe(i,2,sq)
        if(!(num%i)) return false;
    return true;
}
void solve(){
    int n,m;
    cin>>n>>m;
    if(is_prime(m)){
        foe(i,0,n-1){
            foe(j,0,m-1){
                cout<<i*m+1+(i+j)%m<<' ';
            }
        cout<<endl;
        }
    }
    else{
        foe(i,0,n-1){
            foe(j,0,m-1){
                cout<<i*m+j+1<<' ';
            }
            cout<<endl;
        }
    }
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}