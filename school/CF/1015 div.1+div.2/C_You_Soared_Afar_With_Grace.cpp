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
    arr a(n+1,0),b(n+1,0);
    unordered_map<int,int> mp,loc;
    foe(i,1,n+1) cin>>a[i];
    foe(i,1,n+1) cin>>b[i];
    bool has_ans=true;
    int eql_nums=0,eql=0;
    foe(i,1,n+1){
        mp[a[i]]=b[i];
        loc[a[i]]=i;
        if(a[i]==b[i]){
            eql_nums++;
            eql=a[i];
        }
    }
    foe(i,1,n+1){
        if(i!=mp[mp[i]]){
            has_ans=false;
            break;
        }
    }
    if(n%2){
        if(eql_nums!=1) has_ans=false;
    }
    else{
        if(eql_nums!=0) has_ans=false;
    }
    if(!has_ans){
        cout<<-1<<endl;
        return;
    }
    arr res(n+1,0);
    foe(i,1,n+1){
        mp[mp[i]]=0;
    }
    int k=1;
    foe(i,1,n+1){
        if(mp[i]!=0){
            res[k]=i;
            res[n+1-k]=mp[i];
            k++;
        }
    }
    vector<PII> ans;
    if(eql!=0){
        res[k]=eql;
        k++;
    }
    foe(i,1,n+1){
        if(a[i]!=res[i]){
            int nums=res[i];
            int j=loc[nums];
            ans.push_back({ i,j });
            loc[nums]=i;
            loc[a[i]]=j;
            swap(a[i],a[j]);
        }
    }
    cout<<ans.size()<<endl;
    for(auto &it:ans){
        cout<<it.first<<' '<<it.second<<endl;
    }
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}