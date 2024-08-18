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

const i32 N=0;

bool eq(string &a,string &b){
    int cnt=0;
    for(auto &i:a)
        for(auto &j:b)
            if(i==j) cnt++;
    return (!cnt)?0:1;
}
int lower(vector<int> &str,int val){
    int l=-1,r=str.size();
    while(l+1<r){
        int mid=l+(r-l>>1);
        if(str[mid]>=val) r=mid;
        else l=mid;
    }
    return str[r];
}
int upper(vector<int> &str,int val){
    int l=-1,r=str.size();
    while(l+1<r){
        int mid=l+(r-l>>1);
        if(str[mid]>=val) r=mid;
        else l=mid;
    }
    return str[l];
}
void solve(){
    int n,q;
    cin>>n>>q;
    vector<string> a(n+1);
    unordered_map<string,vector<int>> mp;
    foe(i,1,n){
        cin>>a[i];
        mp[a[i]].push_back(i);
    }
    for(auto &it:mp){
        sort(all(it.second),less<int>());
    }
    int x,y;
    foe(i,1,q){
        cin>>x>>y;
        int l=min(x,y),r=max(x,y);
        if(mp.size()<=2||eq(a[l],a[r])){
            if(eq(a[l],a[r])) cout<<abs(r-l)<<endl;
            else cout<<-1<<endl;
            continue;
        }
        int ll=-1,rr=INF32;
        for(auto &it:mp){
            if(it.first==a[l]||it.first==a[r]) continue;
            ll=max(ll,lower(it.second,l));
            rr=min(rr,upper(it.second,l));
        }
        int s1=INF32,s2=INF32;
        if(ll!=-1) s1=abs(l-ll)+abs(r-ll);
        if(rr!=INF32) s2=abs(l-rr)+abs(r-rr);
        cout<<min(s1,s2)<<endl;
    }
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}