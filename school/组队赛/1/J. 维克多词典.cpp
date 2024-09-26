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
vector<PII> a(14,{0,0});

int W,n,num=0,ans=INF64;

void dfs(int u,int day,int tw){
    if(u==num){
        if(tw!=0) day++;
        ans=min(ans,day);
        return;
    }
    bool f=0;
    foe(i,1,13){
        if(a[i].second==0&&a[i].first){
            if(tw+a[i].first>W) continue;
            a[i].second=1;
            if(tw+a[i].first==W) dfs(u+1,day+1,0);
            else dfs(u+1,day,tw+a[i].first);
            a[i].second=0;
            f=1;
        }
    }
    if(!f){
        foe(i,1,13){
            if(a[i].second==0&&a[i].first){
                a[i].second=1;
                dfs(u+1,day+1,a[i].first);
                a[i].second=0;
                return ;
            }
        }
    }
    
}
void solve(){
    int n;
    cin>>n>>W;

    int l;
    foe(i,0,n-1){
        cin>>l;
        a[l].first++;
    }
    foe(i,1,13) if(a[i].first) num++;
    dfs(0,0,0);
    cout<<ans<<endl;
    

}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}