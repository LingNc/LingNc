#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define yes(res) cout<<((res)?"YES":"NO")<<'\n'
#define foe(i,a,b) for(int i=(a);i<(b);i++)
#define fod(i,a,b) for(int i=(a);i>(b);i--)
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


void print(char ch,int num){
    foe(i,0,num) cout<<ch;
}

void solve(){
    string S,T;
    cin>>S>>T;
    bool a=0,b=0,c=0;
    map<char,int> mp;
    for(auto &it:S){
        mp[it]++;
    }
    if(T=="abc"&&mp['a']>0&&mp['b']>0&&mp['c']>0){
        print('a',mp['a']);
        print('c',mp['c']);
        print('b',mp['b']);
        foe(i,'d','z'+1){
            print(i,mp[i]);
        }
    }
    else{
        foe(i,'a','z'+1){
            print(i,mp[i]);
        }
    }
    cout<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}