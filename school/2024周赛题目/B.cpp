#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define all(a) a.begin(),a.end()
using i32=signed;
using namespace std;

i32 times(i32 num){
    int t=0,res=0;
    while(num){
        t++;
        if(num&1) res+=(i32)pow(2,t)-1;
        num>>=1;
    }
    return res;
}
void solve(){
    int x,y;
    cin>>x>>y;
    cout<<times(y+x)-times(x)<<endl;
}

i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}