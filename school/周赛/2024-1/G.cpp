#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define int long long
#define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;
typedef vector<int> arr;
typedef pair<int,int> PII;

const i32 N=0;

typedef struct{
    int height,income,beauty;
}Peo;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<Peo> a(n);
    foe(i,0,n-1){
        cin>>a[i].height>>a[i].income>>a[i].beauty;
    }
    int he,in,be;
    foe(i,1,m){
        int res=0;
        cin>>he>>in>>be;
        for(auto &it:a){
            int t=0;
            if(he>it.height) t++;
            if(in>it.income) t++;
            if(be>it.beauty) t++;
            if(t>=2) res++;
            if(res) break;
        }
        if(res) cout<<"Congratulations!"<<endl;
        else cout<<"Sorry."<<endl;
    }

}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}