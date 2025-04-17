#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
// #define endl '\n'
using namespace std;
using i32=int;
using i64=long long;
#define int long long
#define all(a) a.begin(),a.end()

bool have_7(int num){
    string temp=to_string(num);
    bool res=0;
    if(temp.find('7')!=string::npos){
        res=true;
    }
    else res=false;
    return res;
}

void solve(){
    int n;
    cin>>n;
    int cnt=0;
    foe(i,1,n+1){
        if(have_7(i)||i%7==0){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}

i32 main(){
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}