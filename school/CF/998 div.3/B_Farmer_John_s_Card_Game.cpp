#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define yes(res) cout<<((res)?"YES":"NO")<<'\n'
#define foe(i,a,b) for(int i=(a);i<(b);i++)
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

bool cmp(pair<i32,vector<i32>> &a,pair<i32,vector<i32>> &b){
    int x=a.second[0],y=b.second[0];
    return x<y;
}

void solve(){
    size_t n,m;
    cin>>n>>m;
    vector<pair<i32,vector<i32>>> mp(n,pair(0,vector(m,0)));
    foe(i,0,n){
        foe(j,0,m){
            cin>>mp[i].second[j];
            mp[i].first=i;
        }
        sort(all(mp[i].second));
    }
    sort(all(mp),cmp);
    if(n==1){
        cout<<1<<endl;
        return;
    }
    bool res=true;
    foe(j,0,m){
        int t=1;
        if(j!=0) t=0;
        foe(i,t,n){
            if(i==0){
                if(mp[i].second[j]<=mp[n-1].second[j-1]){
                    res=false;
                    break;
                }
            }
            else{
                if(mp[i].second[j]<=mp[i-1].second[j]){
                    res=false;
                    break;
                }
            }

        }
        if(!res) break;
    }
    if(!res){
        cout<<-1<<endl;
    }
    else{
        foe(i,0,n) cout<<mp[i].first+1<<' ';
        cout<<endl;
    }
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}