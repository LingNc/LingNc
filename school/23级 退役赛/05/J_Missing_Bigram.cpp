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
    int n;
    cin>>n;
    vector<string> str(n,"");
    foe(i,0,n-2){
        cin>>str[i];
    }
    string res;
    int k=0;
    foe(i,1,n-2){
        if(str[i-1][1]!=str[i][0]){
            string t;
            t.push_back(str[i-1][1]);
            t.push_back(str[i][0]);
            str.insert(str.begin()+i,t);
            k++;
        }
    }
    if(k==0){
        string t;
        char temp=str[n-3][1];
        t.push_back(temp);
        if(temp=='a') t.push_back('b');
        else t.push_back('a');
        str.insert(str.begin()+n-2,t);
    }
    foe(i,0,n-1){
        if(i==0){
            res.push_back(str[i][0]);
            res.push_back(str[i][1]);
        }
        else{
            res.push_back(str[i][1]);
        }
    }
    cout<<res<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}