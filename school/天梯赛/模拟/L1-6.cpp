#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
#define endl '\n'
using i32=int;
using i64=long long;
using namespace std;
#define int long long
typedef vector<int> arr;
using PII=pair<int,int>;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define all(a) a.begin(),a.end();

const int N=1e5+10;
arr a(N,0),b(N,0);
const int max_n=3e4;

void init(){
    foe(i,1,max_n+1){
        a[i]=i*i;
    }
    foe(i,1,max_n+1){
        b[i]=b[i-1]+a[i];
    }
}

void solve(){
    init();
    int n;
    cin>>n;
    int x=2*n*n+n;
    foe(i,x,x+n+1){
        if(i!=x) cout<<" + ";
        cout<<i<<"^2";
    }
    cout<<" ="<<endl;
    foe(i,x+n+1,x+2*n+1){
        if(i!=x+n+1) cout<<" + ";
        cout<<i<<"^2";
    }
}
i32 main(){
    IOS;
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}
