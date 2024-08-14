#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
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

const i32 N=2e5+10;
int a[N];
void solve(){
    memset(a,0,sizeof a);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int m,f=0;
    cin>>m;
    unordered_map<char,int> mp,mp1;
    unordered_map<int,char> mp2,mp3;
    while(m--){
        f=0;mp.clear();mp1.clear();mp2.clear();mp3.clear();
        string s;
        cin>>s;
        if(s.size()!=n){
            cout<<"NO"<<endl;
            continue;
        }
        foe(i,0,s.size()-1){
            if(mp[s[i]]!=0&&mp[s[i]]!=a[i+1]){
                f=1;
                cout<<"NO"<<endl;
                break;
            }
            if(mp2[a[i+1]]!=0&&mp2[a[i+1]]!=s[i]){
                f=1;
                cout<<"NO"<<endl;
                break;
            }
            mp2[a[i+1]]=s[i];
            mp[s[i]]=a[i+1];
        }
        if(f==1) continue;
        fod(i,n-1,0){
            if(mp1[s[i]]!=0&&mp1[s[i]]!=a[i+1]){
                f=1;
                cout<<"NO"<<endl;
                break;
            }
            if(mp3[a[i+1]]!=0&&mp3[a[i+1]]!=s[i]){
                f=1;
                cout<<"NO"<<endl;
                break;
            }
            mp3[a[i+1]]=s[i];
            mp1[s[i]]=a[i+1];
        }
        if(f==1) continue;
        foe(i,0,n-1){
            if(mp[s[i]]!=mp1[s[i]]){
                f=1;
                cout<<"NO"<<endl;
                break;
            }
        }
        if(f==0)
            cout<<"YES"<<endl;
    }
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}