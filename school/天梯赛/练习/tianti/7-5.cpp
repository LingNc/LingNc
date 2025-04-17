#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
// #define endl '\n'
using namespace std;
using i32=int;
using i64=long long;
#define int long long


void solve(){
    string str;
    cin>>str;
    // int temp;
    vector<int> res;
    foe(i,0,4){
        int t=1;
        int cnt=0;
        string temp=str.substr(i*8,8);
        reverse(temp.begin(),temp.end());
        foe(j,0,8){
            cnt+=t*(temp[j]-'0');
            t*=2;
        }
        res.push_back(cnt);
    }
    foe(i,0,4){
        cout<<res[i];
        if(i!=3) cout<<'.';
    }
    cout<<endl;
}

i32 main(){
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}