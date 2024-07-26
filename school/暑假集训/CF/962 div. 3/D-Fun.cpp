#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)

using namespace std;

const int N=1e6+10;
int n,x;
void solve(){
    cin>>n>>x;
    int a,b,c;
    int sum=0;
    foe(b,1,x-2){
        foe(c,1,x-b){
            sum+=min((n-b*c)/(b+c),x-(b+c));;
        }
    }
    cout<<sum<<endl;
}

signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}