#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)

using namespace std;

const int N=1e6+10;
int n,q;
string a,b;
void solve(){
    cin>>n>>q;
    cin>>a>>b;
    int k1,k2;
    int na[256],nb[256];
    int sum=0;
    foe(i,1,q){
        cin>>k1>>k2;
        sum=0;
        memset(na,0,sizeof na);
        memset(nb,0,sizeof nb);
        foe(j,k1,k2){
            na[a[j-1]]++;
            nb[b[j-1]]++;
        }
        foe(j,'a','z'){
            sum+=abs(na[j]-nb[j]);
        }
        sum/=2;
        cout<<sum<<endl;
    }
}

signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}