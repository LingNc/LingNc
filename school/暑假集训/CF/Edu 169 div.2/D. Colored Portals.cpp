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

void solve(){
    int n,q;
    cin>>n>>q;
    vector<string> a(n+1);
    map<string,int> mp;
    foe(i,1,n){
        cin>>a[i];
        mp[a[i]]++;
    }
    int x,y;
    foe(i,1,q){
        cin>>x>>y;
        int l=min(x,y),r=max(x,y);
        if(mp.size()<=2||a[l]==a[r]){
            if(a[l]==a[r]) cout<<abs(r-l)<<endl;
            else cout<<-1<<endl;
            continue;
        }
        bool res=0;
        foe(i,l,r) if(a[i]!=a[l]&&a[i]!=a[r]){
            res=1;
            break;
        }
        if(res) cout<<abs(r-l)<<endl;
        else{
            int s1,s2;
            foe(i,r,n) if(a[i]!=a[l]&&a[i]!=a[r]){
                s1=abs(l-i)+abs(r-i);
                break;
            }
            fod(i,r,1) if(a[i]!=a[l]&&a[i]!=a[r]){
                s2=abs(l-i)+abs(r-i);
                break;
            }
            cout<<min(s1,s2)<<endl;
        }
    }
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}