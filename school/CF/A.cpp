#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve(){
    int a,b;
    cin>>a>>b;
    int res=b-a;
    if(a==1&&b==1) res++;
    cout<<res<<endl;
}

int main(){
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}