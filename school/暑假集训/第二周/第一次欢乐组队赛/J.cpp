#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define all(a) a.begin(),a.end()

using namespace std;
using i32=signed;
using i64=long long;

const int N=2e5+10;
int arr[N];
void solve(){
    int n;
    cin>>n;
    foe(i,1,n){
        cin>>arr[i];
    }
    int m;
    cin>>m;
    int op,a,b,c,res;

    while(m--) {
        cin>>op;
        if(op) {
            cin>>c;
            res=INT_MAX;
            int sq=(int)sqrt(n)+1;
            int l,r;
            l=max((int)1,c-sq);r=min(n,c+sq);
            foe(i,l,r)
                res=min(res,(c-i)*(c-i)+arr[i]);
            cout<<res<<endl;
        }
        else {
            cin>>a>>b;
            arr[a]=min(arr[a],b);
        }
    }
}
i32 main(){
    IOS;
    int T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}