#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define int long long
using i64=long long;
using namespace std;

const int N=1e5+10;

void solve(){
    int n;
    cin>>n;
    int a[n+1],b[n+1];
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    foe(i,1,n-1){
        cin>>b[i];
    }

    foe(i,1,n-1){
        a[i]=a[i]|b[i];
        a[i+1]=a[i+1]|b[i];
    }
    bool res=true;
    foe(i,1,n-1){
        int t=a[i]&a[i+1];
        if(t!=b[i]){
            res=false;
            break;
        }
    }
    if(res==true){
        for(int i=1;i<=n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    else cout<<-1<<endl;
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}