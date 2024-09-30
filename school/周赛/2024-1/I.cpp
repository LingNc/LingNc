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

void solve(){
    int h,n;
    cin>>h>>n;
    priority_queue<PII,vector<PII>,greater<PII>> q;
    int num;
    arr a(n+1,0),b(n+1,0);
    foe(i,1,n)
        cin>>a[i];
    foe(i,1,n)
        cin>>b[i];
    foe(i,1,n){
        q.push({ 1,i });
    }
    int res;
    while(h>0){
        auto t=q.top();
        q.pop();
        h-=a[t.second];
        res=t.first;
        q.push({ t.first+b[t.second],t.second });
    }
    cout<<res<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}