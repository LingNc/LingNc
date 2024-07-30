#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define long long
using i64=long long;
using namespace std;

const int N=1e5+10;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int sum=0;
    foe(i,0,n-1){
        cin>>a[i];
        sum+=a[i];
    }
    vector<int> b(n,0);
    int avg=0;
    if(sum%2) avg=sum/n+1;
    else avg=sum/n;
    foe(i,0,n-1)
        b[i]=a[i]-avg;
    foe(i,1,n-1){
        b[i]+=max(0,b[i-1]);
        b[i-1]-=max(0,b[i-1]);
    }
    foe(i,0,n-1)
        b[i]+=avg;
    i64 res=1;
    foe(i,0,n-1){
        cout<<b[i]<<' ';
        res*=b[i];
    }
    cout<<endl;
    cout<<res<<endl;
    
}
signed main(){
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}