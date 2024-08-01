#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define all(a) a.begin(),a.end()

using i32=signed;
using i64=long long;
using namespace std;

const int N=1e6+10;
int a[N],b[N],c[N];
void solve(){
    int n;
    cin>>n;
    n--;
    foe(i,0,n-1)
        cin>>a[i];
    b[0]=a[0];
    foe(i,1,n-1) 
        b[i]=a[i]|a[i-1];
    b[n]=a[n-1];
    foe(i,0,n-1) 
        c[i]=b[i]&b[i+1];
    bool res=true;
    foe(i,0,n-1)
        if(c[i]!=a[i]) 
            res=false;
    if(res)
        foe(i,0,n)
            cout<<b[i]<<' ';
    else
        cout<<-1;
    cout<<endl;
}
signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}