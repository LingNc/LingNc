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

void solve(){
    int n,m;
    cin>>n>>m;
    cin.get();
    m++;
    int k=0;
    int have=false;
    foe(i,0,n){
        string str;
        getline(cin,str);
        // cin.get();
        if(str.find("easy")==string::npos&&str.find("qiandao")==string::npos){
            // if(m==0) cout<<str<<endl;
            k++;
            if(k==m){
                cout<<str<<endl;
                have=true;
            }
        }
    }
    if(!have) cout<<"Wo AK le"<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}
