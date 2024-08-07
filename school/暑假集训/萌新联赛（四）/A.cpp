#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)

using namespace std;
using i32=signed;
const int N=10;
int prime(int n){
    if(n<=3) return 1;
    int sq=(int)sqrt(n);
    for(int i=2;i<=sq;i++){
        if(n%i==0) return 0;
    }
    return 1;
}

void solve(){
    int x;
    cin>>x;
    if(prime(x)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
i32 main(){
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}