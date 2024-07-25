#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define int long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
using namespace std;

const int N=2e5+10;
int q[N],hh,tt,a[N],res,n,m;
void solve(){
    cin>>n>>m;
    foe(i,0,n-1)
        cin>>a[i];
    hh=0,tt=-1,res=-1;
    int sum=0;
    sort(a,a+n);
    foe(i,0,n-1){
        q[++tt]=a[i];
        sum+=a[i];
        while(hh<=tt&&(q[tt]-q[hh]>1||sum>m))
            sum-=q[hh++];
        res=max(res,sum);
    }
    cout<<res<<endl;
}
signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}