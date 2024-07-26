#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)

using namespace std;

const int N=30;
int n,q;
string a,b;
int na[N][26],nb[N][26];
void solve(){
    cin>>n>>q;
    cin>>a>>b;
    foe(i,1,n){
        na[i][a[i]-'a']++;
        nb[i][b[i]-'a']++;
    }
    foe(i,1,n-1){
        foe(j,0,25){
            na[i][j]+=na[i-1][j];
            nb[i][j]+=nb[i-1][j];
        }
    }
    int k1,k2;
    int sum=0;
    foe(i,1,q){
        cin>>k1>>k2;
        sum=0;
        foe(j,0,25){
            sum+=abs(na[k2][j]-na[k1-1][j]-(nb[k2][j]-nb[k1-1][j]));
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