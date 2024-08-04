#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define all(a) a.begin(),a.end()

using namespace std;
using i32=signed;
using i64=long long;

void solve(){
    int n[4]={ 0 };
    string m;
    int b,d,c;
    cin>>b;
    c=4*b;
    d=0;
    cin>>m;
    foe(i,0,c-1){
        if(m[i]=='A')n[0]++;
        else if(m[i]=='B')n[1]++;
        else if(m[i]=='C')n[2]++;
        else if(m[i]=='D')n[3]++;
    }
    foe(i,0,3){
        if(n[i]<=b)d=d+n[i];
        else d=d+b;
    }
    cout<<d<<endl;
}
i32 main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}