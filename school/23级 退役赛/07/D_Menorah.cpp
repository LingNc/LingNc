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
// #define int long long
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
    int one1=0,one2=0,eq=0;
    foe(i,0,n){
        if(str1[i]==str2[i]&&str1[i]=='1'){
            eq++;
        }
        if(str1[i]=='1') one1++;
        if(str2[i]=='1') one2++;
    }
    if(one1!=one2&&(1+n-one1)!=one2||one1==0){
        cout<<-1<<endl;
        return;
    }
    int res=0;
    if(one1!=1+n-one1&&one1!=one2){
        res+=1;
    }
    res+=2*(one2-eq);
    cout<<res<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}