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

const int N=2e5+10;
int a[N];
void solve(){
    int n;
    cin>>n;
    foe(i,0,n-1) cin>>a[i];
    int ans=0;
    sort(a,a+n,less<int>());
    foe(i,0,n-1){
        if(!(a[i]%2))
            ans++;
    }
    if(a[n-1]%2){
        cout<<ans<<endl;
    }
    else{
        if(ans==n){
            cout<<0<<endl;
            return;
        }
        int max_odd=-1,max_even=-1;
        bool flag=0;
        fod(i,n-1,0){
            if(flag&&a[i]%2==0){
                max_even=a[i];
                break;
            }
            if(!flag&&a[i]%2){
                max_odd=a[i];
                flag=1;
            }
        }
        foe(i,0,n-1){
            if(a[i]%2==0&&a[i]<max_odd) max_odd+=a[i];
        }
        if(max_odd>a[n-1]&&max_even!=-1)
            cout<<ans<<endl;
        else
            cout<<ans+1<<endl;
    }
}
i32 main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}