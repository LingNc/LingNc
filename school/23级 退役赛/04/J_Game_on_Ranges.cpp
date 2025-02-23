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
    vector<pair<int,pair<int,int>>> list(n,{ 0,{ 0,0 } });
    int l,r;
    foe(i,0,n){
        cin>>l>>r;
        list[i]={ r-l,{ l,r } };
    }
    sort(all(list));
    unordered_map<int,bool> mp;
    foe(i,0,n){
        auto t=list[i].second;
        if(t.first==t.second){
            mp[t.first]=1;
            cout<<t.first<<' '<<t.second<<' '<<t.first<<endl;
        }
        if(mp.count(t.first)==0){
            mp[t.first]=1;
            cout<<t.first<<' '<<t.second<<' '<<t.first<<endl;
        }
        if(mp.count(t.second)==0){
            mp[t.second]=1;
            cout<<t.first<<' '<<t.second<<' '<<t.second<<endl;
        }
        if(mp.count(t.first)==1&&mp.count(t.second)==1){
            foe(k,t.first,t.second+1){
                if(mp[k]==0){
                    mp[k]=1;
                    cout<<t.first<<' '<<t.second<<' '<<k<<endl;
                    break;
                }
            }
        }
    }
    cout<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}