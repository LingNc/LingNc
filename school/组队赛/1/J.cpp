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

void solve(){
    int n,W;
    cin>>n>>W;
    vector<PII> a(14,{0,0});
    int num;
    foe(i,0,n-1){
        cin>>num;
        a[num-1].first++;
    }
    sort(all(a),greater<PII>());
    
    // for(auto &it:a){
    //     cout<<it.first<<' ';
    // }
    int temp;
    int res=0;
    foe(i,0,12){
        if(a[i].second||a[i].first==0) continue;
        temp=W-a[i].first;
        a[i].second=1;
        int p=i+1;
        while(a[p].first&&p<=12&&temp){
            if(a[p].first<=temp&&a[p].second==0){
                a[p].second=1;
                temp-=a[p].first;
                p=i+1;
            }
            else{

                p++;
            }
        }
        res++;
    }

    int ci=0,k;
    for(auto &it:a){
        it.second=0;
    }
    for(int i=0;i<=12;i++){
        if(a[i].second==1)break;
        else{
            if(a[i].first==W){
                ci++;
                continue;
            }else{
                k=W-a[i].first;
                for(int j=12;j>=0;j--){
                    if(a[j].second==1)continue;
                    if(i==j){
                        ci++;
                        break;
                    }
                    if(a[j].first<=k){
                        k-=a[j].first;
                        a[j].second=1;
                    }else{
                        ci++;
                        break;
                    }
                }
            }
        }
    }
    cout<<min(res,ci)<<endl;

}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}