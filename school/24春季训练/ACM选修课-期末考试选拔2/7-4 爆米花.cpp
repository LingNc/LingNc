#include<iostream>
#include<algorithm>
#include<string>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(int i=a;i<=b;i++)

using namespace std;

void solve(){
    ll n;
    cin>>n;
    ll sum=(1+n)*n/2;
    cout<<sum-n+1<<endl;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
