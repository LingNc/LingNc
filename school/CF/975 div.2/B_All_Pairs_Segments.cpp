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
    int n,q;
    cin>>n>>q;
    map<int,int> mp;
    vector<int> a(n+2,0),ori(n+2,0);
    foe(i,1,n)
        cin>>ori[i];
    foe(i,1,n){
        a[i]=i*(n-i)+i-1;
        mp[a[i]]++;
        if(i!=n){
            int temp=a[i]-(i-1);
            mp[temp]+=ori[i+1]-ori[i]-1;
        }
    }
    int num;
    foe(i,1,q){
        cin>>num;
        cout<<mp[num]<<' ';
    }
    cout<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}