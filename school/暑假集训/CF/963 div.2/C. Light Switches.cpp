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

// const int N=2e5+10;
// int a[N];
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(2*k,0);
    vector<int> res;
    int t=0,tol=0,temp=0;
    int mit=INT_MAX,mat=INT_MIN,max_t=-1;
    foe(i,0,n-1){
        cin>>t;
        max_t=max(max_t,t);
        temp=(t)%(2*k);
        if(temp>k) temp=2*k-temp;
        if(!a[temp]){
            tol++;
            a[temp]=1;
            mit=min(mit,temp);
            mat=max(mat,temp);
        }
    }
    foe(i,0,2*k-1){
        if(a[i]-mit==k) cout<<-1<<endl;
        else if(a[i]>k)
    }
}
i32 main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}