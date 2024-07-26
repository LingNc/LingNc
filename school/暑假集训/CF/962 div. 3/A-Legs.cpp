#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
using namespace std;

string road;
int n;
double a,b;
void solve(){
    cin>>n;
    n=n/2;
    if(n%2==1) n=n/2+1;
    else n=n/2;
    cout<<n<<endl;

}

signed main(){
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}