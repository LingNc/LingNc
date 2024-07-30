#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define ll long long
using i64=long long;
using namespace std;
const int N=1e4+10;
int res[N];
void solve(){
    int n,k;
    cin>>n>>k;
    foe(i,0,n-1) cin>>res[i];
    sort(res,res+n,less<int>());
    int pla=0;
    int last_q=0;
    k*=2;
    foe(i,0,n-1){
        if(res[i]<=k){
            last_q=res[i];
            k=max(2*last_q,k);
        }
        else{
            i--;
            pla++;
            last_q=k;
            k=max(2*last_q,k);
        }
    }
    cout<<pla<<endl;
}
signed main(){
    int T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}