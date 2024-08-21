#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){return b==0?a:gcd(b,a%b);}
template<typename iii> iii lcm(iii a,iii b){return a/gcd(a,b)*b;}
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
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

const i32 N=0;


void solve(){
    string str1,str2;
    cin>>str1>>str2;
    arr a(26,0),b(26,0);
    for(auto &it:str1) a[it-'a']++;
    for(auto &it:str2) b[it-'a']++;
    int cnt=0;
    int k=0;
    foe(i,0,25){
        if(abs(a[i]-b[i])==1) k=i;
        cnt+=abs(a[i]-b[i]);
    }
    if(cnt!=1){
        cout<<0<<endl;
        return ;
    }
    char t=k+'a';
    int l=0,r=0;
    str1+='0';
    foe(i,0,str1.size()){
        if(str1[i]==str2[i]&&str1[i]==t&&str1[i-1]!=t){
            l=i;
        }
        if(str1[i]!=str2[i]){
            r=i;
            if(str1[r-1]!=str1[l]) l=r;
            break;
        }
    }
    cout<<r-l+1<<endl;
    foe(i,l,r) cout<<i<<' '<<t<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}