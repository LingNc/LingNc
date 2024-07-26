#include <bits/stdc++.h>

using u32=unsigned;
using i64=long long;
using u64=unsigned long long;

void solve(){
    int n,x;
    std::cin>>n>>x;

    i64 ans=0;
    for(int a=1; a<=n; a++){
        for(int b=1; a*b<=n&&a+b<=x; b++){
            ans+=std::min((n-a*b)/(a+b),x-a-b);
        }
    }
    std::cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin>>t;

    while(t--){
        solve();
    }

    return 0;
}