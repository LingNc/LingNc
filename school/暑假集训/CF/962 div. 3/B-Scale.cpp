#include<bits/stdc++.h>
//#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)

using namespace std;

const int N=1e3+10;
int t,k;
char A[N][N];
void solve(){
    cin>>t>>k;
    memset(A,0,sizeof A);
    foe(i,1,t)
        foe(j,1,t){
            cin>>A[i][j];
        }
    for(int i=1;i<=t;i+=k){
        for(int j=1;j<=t;j+=k){
            cout<<A[i][j];
        }
        cout<<endl;
    }
}

int main(){
    //IOS;
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}