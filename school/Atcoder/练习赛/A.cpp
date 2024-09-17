#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)

using namespace std;
using i32=signed;
const int N=10;

void solve(){
    int a,b,c;
    string str;
    cin>>a>>b>>c>>str;
    cout<<a+b+c<<' '<<str<<endl;
}
i32 main(){
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}