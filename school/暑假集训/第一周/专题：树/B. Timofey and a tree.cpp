#include<bits/stdc++.h>
#define ll long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
using i64=long long;
using namespace std;

const int N=1e5+10;
int a[N],b[N],col[N],res[N];
void solve(){
    int n;
    cin>>n;
    foe(i,1,n-1)
        cin>>a[i]>>b[i];
    foe(i,1,n)
        cin>>col[i];
    int sum=0;
    foe(i,1,n-1)
        if(col[a[i]]!=col[b[i]])
            res[a[i]]++,res[b[i]]++,sum++;

    foe(i,1,n){
        if(res[i]==sum){
            cout<<"YES"<<endl;
            cout<<i<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}
signed main(){
    IOS;
    int T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}