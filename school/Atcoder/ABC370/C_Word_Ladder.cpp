#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define yes(res) cout<<((res)?"Yes":"No")<<'\n'
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
typedef pair<char,int> PII;

const i32 N=0;

void solve(){
    string S,T;
    cin>>S>>T;
    vector<string> X;
    foe(i,0,S.size()-1){
        if(S[i]>T[i]){
            S[i]=T[i];
            X.push_back(S);
        }
    }
    fod(i,S.size()-1,0){
        if(S[i]<T[i]){
            S[i]=T[i];
            X.push_back(S);
        }
    }
    cout<<X.size()<<endl;
    for(auto &it:X){
        cout<<it<<endl;
    }

}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}