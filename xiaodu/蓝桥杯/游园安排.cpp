#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define yes(res) cout<<((res)?"YES":"NO")<<'\n'
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define all(a) a.begin(),a.end()
#define INF64 0x3f3f3f3f3f3f3f3f
#define INF32 0x3f3f3f3f
#define int long long
#define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;
typedef vector<int> arr;
typedef pair<int,int> PII;

const i32 N=0;

string name(string &str,int site){
    int len=1;
    int p=site;
    while(++p!=str.size()){
        if(isupper(str[p])) break;
        len++;
    }
    return str.substr(site,len);
}

bool cmp(const string &a,const string &b){
    if(a.size()!=b.size()){
        return a.size()<b.size();
    }
    else{
        return a<b;
    }
}


void solve(){
    string str;
    cin>>str;
    vector<string> a;
    foe(i,0,str.size()-1){
        if(isupper(str[i])){
            a.push_back(name(str,i));
        }
    }
    sort(all(a),cmp);

}

i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}