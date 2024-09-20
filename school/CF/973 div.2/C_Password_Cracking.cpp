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
int n;
int query(string &str){
    cout<<"? "<<str<<endl;
    int res;
    cin>>res;
    return res;
}

int dfs(string &str,bool f){
    int res,ans;
    if(str.size()==n){
        cout<<"! "<<str<<endl;
        return true;
    }
    if(str.size()==0){
        str.push_back('0');
        res=query(str);
        if(!res) str[0]='1';
        if(n==1){
            cout<<"! "<<str<<endl;
            return false;
        }
    }
    if(f){
        str.push_back('0');
        res=query(str);
        if(res) return dfs(str,f);
        str.pop_back();
        str.push_back('1');
        res=query(str);
        if(res) return dfs(str,f);
        str.pop_back();
        f=!f;
    }
    if(!f){
        str.insert(str.begin(),'0');
        res=query(str);
        if(res) return dfs(str,f);
        str.erase(str.begin());
        str.insert(str.begin(),'1');
        return dfs(str,f);
    }
}

void solve(){
    cin>>n;
    bool forward=1;
    string res;
    dfs(res,forward);
}
i32 main(){
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}