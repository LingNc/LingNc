    #include<bits/stdc++.h>
    #define int long long
    #define endl '\n'
    using namespace std;
    void solve(){
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        int ans=0;
        for(int i=0;i<=n-3;i++){
            if(a.substr(i,3)=="x.x"&&b.substr(i,3)=="..."||a.substr(i,3)=="..."&&b.substr(i,3)=="x.x")
                ans++;
        }
        cout<<ans<<endl;
    }
    signed main(){
        int T=1;
        cin>>T;
        while(T--) solve();
        return 0;
    }