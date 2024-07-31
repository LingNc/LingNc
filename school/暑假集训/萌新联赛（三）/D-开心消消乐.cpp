#include<bits/stdc++.h>
#define ll long long 
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define all(a) a.begin(),a.end()
using i32=signed;
using namespace std;

const int N=1e6+10;
int q[N];
int hh,tt;

void solve(){
    int n;
    cin>>n;
    hh=0,tt=0;
    q[0]=-1;
    foe(i,0,n-1) cin>>q[++tt];
    int t2=tt;
    int ans=0;
    while(tt>=hh){
        int t=q[tt--];
        if(t==0) continue;
        if(t!=q[t2]||tt<0){
            ans++;
            t2=tt+1;
        }
    }
    cout<<ans<<endl;
}

i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}