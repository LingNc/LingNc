#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){return b==0?a:gcd(b,a%b);}
template<typename iii> iii lcm(iii a,iii b){return a/gcd(a,b)*b;}
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
    string x1,x2;
    int p1,p2;
    cin>>x1>>p1;
    cin>>x2>>p2;
    int res=0;
    int len1=x1.size()+p1,len2=x2.size()+p2;
    if(len1==len2){
        int l1=x1.size(),l2=x2.size();
        if(l1>l2){
            foe(i,0,l1-l2){
                x2+="0";
            }
        }
        else if(l1<l2){
            foe(i,0,l2-l1){
                x1+="0";
            }
        }
        if(x1>x2) res=1;
        else if(x1<x2) res=2;
        else res=0;
    }
    else{
        if(len1>len2) res=1;
        else if(len1<len2) res=2;
        else res=0;
    }
    if(res==0) cout<<"="<<endl;
    else if(res==1) cout<<">"<<endl;
    else cout<<"<"<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}