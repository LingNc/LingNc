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
typedef pair<int,int> PII;

const i32 N=0;

void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    arr odd(26,0),even(26,0);
    foe(i,0,n-1){
        if(i%2) even[str[i]-'a']++;
        else odd[str[i]-'a']++;
    }
    int mo=-1,me=-1;
    foe(i,0,25){
        mo=max(mo,odd[i]);
        me=max(me,even[i]);
    }
    int res=INF64;
    if(n%2==0) res=n-mo-me;
    else{
        foe(i,0,n-1){
            if(i%2) even[str[i]-'a']--;
            else odd[str[i]-'a']--;

            mo=-1,me=-1;
            foe(j,0,i-1){
                mo=max(mo,odd[j]);
                me=max(me,even[j]);
            }
            foe(j,i+1,25){
                mo=max(mo,even[j]);
                me=max(me,odd[j]);
            }

            res=min(res,n-mo-me);

            if(i%2) even[str[i]-'a']++;
            else odd[str[i]-'a']++;
        }
    }
    if(n==1) cout<<1<<endl;
    else cout<<res<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
};