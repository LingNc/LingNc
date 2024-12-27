#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){return b==0?a:gcd(b,a%b);}
template<typename iii> iii lcm(iii a,iii b){return a/gcd(a,b)*b;}
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

map<string,int> mp1;
map<int,map<string,string>,greater<int>> mp2;
bool st[10];
string path;
arr a(5,0);

int scores(){
    int res=0;
    for(auto &it:path){
        res+=a[it-'A'];
    }
    return res;
}
void dfs(int u,int end){
    if(u==end){
        return;
    }
    foe(i,1,5){
        if(st[i]==true) continue;
        st[i]=true;
        path.push_back('A'+i-1);
        int sco=scores();
        auto t=path;
        sort(all(t));
        mp2[sco][t]=t;
        dfs(u+1,end);
        path.pop_back();
        st[i]=false;
    }
}

void solve(){
    foe(i,0,4) cin>>a[i];
    dfs(0,5);
    for(auto &it:mp2){
        for(auto &jt:it.second){
            cout<<jt.first<<endl;
        }
    }
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}