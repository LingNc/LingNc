#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define int long long
#define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;
typedef vector<int> arr;
typedef pair<int,int> PII;

const i32 N=0;

int prime(int n){
    if(n<=3) return (n<=1)?0:1;
    int sq=(int)sqrt(n);
    for(int i=2;i<=sq;i++){
        if(n%i==0) return 0;
    }
    return 1;
}

void solve(){
    string str;
    cin>>str;
    int n;
    n=stod(str);
    bool res=false;
    if(prime(n)){
        foe(i,0,str.size()-1){
            if(prime(i+1)){
                auto t=str[str.size()-1-i]-'0';
                if(prime(t)){
                    res=true;
                }
            }
        }
    }
    if(res) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}