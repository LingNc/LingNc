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


void solve(){
    string a,s;
    cin>>a>>s;
    reverse(all(a)),reverse(all(s));
    // foe(i,0,s.size()-a.size()){
    //     a.push_back('0');
    // }
    string b;
    bool res=true;
    for(int pa=0,ps=0;pa<a.size();pa++,ps++){
        if(ps>=s.size()){
            res=false;
            break;
        }
        int ns=s[ps]-'0',na=a[pa]-'0';
        if(ns>=na){
            if(ns==na&&na==1){
                if(ps+1>=s.size()||s[ps+1]>'1'){
                    b.push_back('0'+ns-na);
                }
                else{
                    ns+=10;
                    ps++;
                    b.push_back('0');
                    b.push_back('1');
                }

            }
            else
                b.push_back('0'+ns-na);
        }
        if(ns<na){
            if(ps+1>=s.size()||s[ps+1]>'1'){
                res=false;
                break;
            }
            ns+=10;
            ps++;
            b.push_back('0'+ns-na);
        }
    }
    reverse(all(b));
    if(res){
        int zero=(b[0]=='0');
        for(auto &it:b){
            if(it=='0'&&zero){
                continue;
            }
            else zero=false;
            cout<<it;
        }
        cout<<endl;
    }
    else cout<<-1<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}