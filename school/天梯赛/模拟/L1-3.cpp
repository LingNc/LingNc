#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
#define endl '\n'
using i32=int;
using i64=long long;
using namespace std;
#define int long long
typedef vector<int> arr;
using PII=pair<int,int>;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define all(a) a.begin(),a.end();

void print(int w){
    cout<<"Gong xi nin! Nin de ti zhong yue wei: "<<w<<" duo jin"<<endl;
}

void solve(){
    int w;
    cin>>w;
    if(w<=100){
        if(w%10==0) print(w-10);
        else print(w/10*10);
    }
    else{
        print(100);
    }
}
i32 main(){
    IOS;
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}
