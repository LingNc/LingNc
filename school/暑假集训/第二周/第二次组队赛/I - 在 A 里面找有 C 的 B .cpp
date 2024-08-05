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

typedef pair<string,string> PII;

bool KMP(string &s,string &p){
    // s[]是长文本，p[]是模式串，n是s的长度，m是p的长度
    //求模式串的Next数组：
    int n=s.size(),m=p.size();
    vector<int> ne(n,0);
    for(int i=2,j=0; i<=m; i++)
    {
        while(j&&p[i]!=p[j+1]) j=ne[j];
        if(p[i]==p[j+1]) j++;
        ne[i]=j;
    }

    //匹配
    for(int i=1,j=0; i<=n; i++){
        while(j&&s[i]!=p[j+1]) j=ne[j];
        if(s[i]==p[j+1]) j++;
        if(j==m){
            j=ne[j];
            //匹配成功后的逻辑
            return true;
        }
    }
    return false;
}
void solve(){
    int n;
    cin>>n;
    string A,C;
    cin>>A>>C;
    // vector<PII> arr;
    string B1,B2;
    foe(i,1,n){
        cin>>B1>>B2;
        if(KMP(A,B1)&&KMP(B2,C))
            cout<<i<<' ';
    }
    cout<<endl;

}
i32 main(){
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}