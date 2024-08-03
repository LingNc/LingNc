#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define all(a) a.begin(),a.end()

using namespace std;
using i32=signed;
using i64=long long;


int num(string &str){
    int res=0;
    for(auto &it:str){
        if(it=='#') res++;
    }
    return res;
}
void solve(){
    int n,m;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    int num_a=num(a),num_b=num(b);
    int aa=num_b/25+1,bb=num_b%2;
    int alpha=1;
    for(auto &i:a){
        if(aa&&i=='#') i='a',aa--;
        else if(i=='#'&&bb&&alpha==26-bb){
            alpha=0;
            i=(alpha++)%26+'a';
            bb=0;
        }
        else if(i=='#') i=(alpha++)%26+'a';
    }
    cout<<a<<endl;
}
i32 main(){
    int T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}