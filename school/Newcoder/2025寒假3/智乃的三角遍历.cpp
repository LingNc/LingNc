#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){return b==0?a:gcd(b,a%b);}
template<typename iii> iii lcm(iii a,iii b){return a/gcd(a,b)*b;}
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define yes(res) cout<<((res)?"YES":"NO")<<'\n'
#define foe(i,a,b) for(int i=(a);i<(b);i++)
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

int f(int n){
    return (n+2)*(n-1)/2-n+2;
}

void solve(){
    int n;
    cin>>n;
    n++;
    cout<<"Yes"<<endl;
    foe(i,1,n){
        int start=f(i);
        int end=start+i-1;
        int next_end=end+i+1;
        foe(j,start,end+1){
            cout<<j<<' ';
        }
        if(start!=1){
            foe(k,0,i){
                next_end-=i+1;
                if(k!=0) cout<<next_end<<' ';
                next_end+=i;
                if(k!=i-1) cout<<next_end<<' ';
            }
        }
    }
    int start=f(n);
    foe(i,0,n) cout<<start+i<<' ';
    int end=start+n-1;
    fod(i,n,2){
        end-=i;
        cout<<end<<' ';
    }
}
i32 main(){
    IOS;
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}