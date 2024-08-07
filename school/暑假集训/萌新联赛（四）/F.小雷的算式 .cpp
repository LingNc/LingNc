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

int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
int lcm(int a,int b){ return a/gcd(a,b)*b; }

void solve(){
    int res=0,n=1;
    stringstream ss;
    string str;
    cin>>str;
    foe(i,0,str.size()-1)
        if(str[i]=='+'){
            str[i]=' ';
            n++;
        }
    ss<<str;
    int num;
    vector<int> ans;
    while(n--){
        ss>>num;
        ans.push_back(num);
        res+=num;
    }
    sort(all(ans),greater<int>());
    foe(i,0,ans.size()-1){
        cout<<ans[i];
        if(i!=ans.size()-1) cout<<'+';
    }
    cout<<endl<<res;
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}