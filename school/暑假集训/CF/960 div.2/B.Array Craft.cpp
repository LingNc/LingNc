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
int a[N],res,n,x,y;
void solve(){
    cin>>n>>x>>y;
    int flag=-1;
    for(int i=y-1;i>=1;i--){
      a[i]=flag;
      flag=-flag;
    }
    flag=-1;
    foe(i,x+1,n){
        a[i]=flag;
        flag=-flag;
    }
    foe(i,y,x){
        a[i]=1;
    }
    foe(i,1,n){
        cout<<a[i]<<' ';
    }
    cout<<endl;
}
signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}