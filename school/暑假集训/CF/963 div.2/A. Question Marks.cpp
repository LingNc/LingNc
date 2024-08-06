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

int a[4];
void solve(){
    memset(a,0,sizeof a);
    int n,res=0;
    cin>>n;
    string str;
    cin>>str;
    for(auto &i:str)
        if(i!='?') a[i-'A']++;
    for(auto &i:a)
        res+=min(i,n);
    cout<<res<<endl;
}
i32 main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}