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
    string str1,str2;
    cin>>str1>>str2;
    int num_1=0,num_2=0;
    foe(i,0,n){
        if(!(i%2)){
            if(str1[i]=='0') num_1++;
            if(str2[i]=='0') num_2++;
        }
        else{
            if(str1[i]=='0') num_2++;
            if(str2[i]=='0') num_1++;
        }
    }
    bool res=0;
    if(n%2){
        int temp=n/2+1;
        if(num_1>=temp&&num_2>=n/2){
            res=true;
        }
    }
    else{
        int temp=n/2;
        if(num_1>=temp&&num_2>=temp){
            res=true;
        }
    }
    yes(res);
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}
