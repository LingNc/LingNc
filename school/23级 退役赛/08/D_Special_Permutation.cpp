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
    int n,a,b;
    cin>>n>>a>>b;
    unordered_map<int,bool>mp;
    arr res1,res2;
    if(b<a){
        if(n-a<n/2-1||b-1<n/2-1){
            cout<<-1<<endl;
            return;
        }
    }
    else{
        if(n-a-1<n/2-1||b-2<n/2-1){
            cout<<-1<<endl;
            return;
        }
    }
    mp[b]=1;
    int k=0;
    res1.push_back(a);
    mp[a]=1;
    foe(i,0,n){
        // if(n-i<1){
        //     cout<<-1<<endl;
        //     return;
        // }
        if(mp[n-i]==0){
            res1.push_back(n-i);
            mp[n-i]=1;
            k++;
        }
        if(k>=n/2-1) break;
    }
    k=0;
    mp[b]=0;
    foe(i,0,n){
        // if(1+i>n){
        //     cout<<-1<<endl;
        //     return;
        // }
        if(mp[1+i]==0){
            // if(1+i>b){
            //     cout<<-1<<endl;
            //     return;
            // }
            res2.push_back(1+i);
            k++;
        }
        if(k>=n/2) break;
    }
    // if(res2.size()<n/2){
    //     cout<<-1<<endl;
    //     return;
    // }
    foe(i,0,n/2){
        cout<<res1[i]<<' ';
    }
    foe(i,0,n/2){
        if(i!=0) cout<<' '<<res2[i];
        else cout<<res2[i];
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