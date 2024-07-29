#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define ll long long
using i64=long long;
using namespace std;

const int N=1e6+10;
int a[N];
void solve(){
    int n;
    cin>>n;
    foe(i,0,n-1){
        cin>>a[i];
    }
    foe(i,1,n-1){
        if(a[i]%2!=a[0]%2){
            cout<<-1<<endl;
            return ;
        }
    }
    vector<int> ans;
    while(1){
        int l=1e9+1,r=-1;
        foe(i,0,n-1){
            l=min(l,a[i]);
            r=max(r,a[i]);
        }
        if(l==0&&r==0) break;
        int mid=(l+r)>>1;
        ans.push_back(mid);
        foe(i,0,n-1)
            a[i]=abs(a[i]-mid);
    }
    cout<<ans.size()<<endl;
    for(auto &i:ans){
        cout<<i<<' ';
    }
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}