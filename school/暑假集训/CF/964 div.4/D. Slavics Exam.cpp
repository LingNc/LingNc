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

void solve(){
    string s1,s2;
    cin>>s1>>s2;
    string res;
    int p1=0,p2=0;
    while(p1<s1.size()&&p2<s2.size()){
        while(s1[p1]!=s2[p2]&&s1[p1]!='?'&&p1<s1.size())
            p1++;
        if(p1==s1.size()) break;
        s1[p1++]=s2[p2++];
    }
    for(auto &i:s1)
        if(i=='?') i=s2[p2-1];
    if(p2==s2.size()){
        cout<<s1<<endl;
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}