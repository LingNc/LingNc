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

void solve(){
    string str;
    cin>>str;
    foe(i,0,(str.size()-1)/2){
        if(str[str.size()-1-i]=='a'){
            if(str[i]=='a') continue;
            else{
                cout<<"YES"<<endl;
                str.insert(str.begin()+i+1,'a');
                cout<<str<<endl;
                return ;
            }
        }
        else if(str[i]=='a'){
            if(str[str.size()-1-i]=='a'){
                cout<<"YES"<<endl;
                str.insert(str.begin()+str.size()-1-i,'a');
                cout<<str<<endl;
                return;
            }
            else continue;
        }
        else{
            cout<<"YES"<<endl;
            str.insert(str.begin()+1,'a');
            cout<<str<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}