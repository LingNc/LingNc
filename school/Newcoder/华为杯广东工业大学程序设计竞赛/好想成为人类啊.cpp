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
    int n,m;
    cin>>n>>m;
    string str,need;
    cin>>str>>need;
    arr st(n,0);
    vector<PII> mp;
    int res_num=0;
    for(auto it=str.begin();it!=str.end();it++){
        it=search(it,str.end(),boyer_moore_searcher(all(need)));
        if(it!=str.end()){
            res_num++;
        }
        else{
            break;
        }
        int pos=it-str.begin();
        mp.push_back({ pos,pos+m-1 });
        // st[pos]+=1;
        // st[pos+m]-=1;
    }
    // arr b(n+1,0);
    // foe(i,1,n+1){
    //     b[i]=b[i-1]+st[i-1];
    // }
    int res=0;
    if(!mp.empty()){
        res=1;
        int now=mp[0].second;
        for(auto &it:mp){
            if(it.second-now>=m){
                res++;
                now=it.second;
            }
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