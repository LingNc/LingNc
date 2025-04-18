#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
// #define endl '\n'
using namespace std;
using i32=int;
using i64=long long;
#define int long long
typedef pair<int,int> PII;
#define all(a) a.begin(),a.end()

void print(int num,char ch){
    foe(i,0,num) cout<<ch;
}

void solve(){
    int n;
    char ch;
    cin>>n>>ch;
    int res=sqrt((n+1)/2);
    fod(i,res,0){
        int j=2*i-1;
        print(res-i,' ');
        print(j,ch);
        cout<<endl;
    }
    foe(i,2,res+1){
        int j=2*i-1;
        print(res-i,' ');
        print(j,ch);
        cout<<endl;
    }
    cout<<n-2*res*res+1<<endl;
}

i32 main(){
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}