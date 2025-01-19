#include<bits/stdc++.h>
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

void solve(){
    int m,n,b;
    cin>>m>>n;
    arr x(2*m+2,0),a(m+1,0);
    foe(i,1,m+1){
        cin>>a[i];
        x[a[i]]++;
    }
    b=0;
    foe(i,1,n/2+1){
        if(2*i==n) b+=x[i]/2;
        else b+=min(x[i],x[n-i]);
    }
    cout<<b<<endl;
}

i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}