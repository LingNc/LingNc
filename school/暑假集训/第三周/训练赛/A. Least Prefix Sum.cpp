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


void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n+1,0);
    foe(i,1,n) cin>>arr[i];
    priority_queue<int,vector<int>,less<int>> q1,q2;
    int sum=0,res=0;
    fod(i,m,2){
        sum+=arr[i];
        q1.push(arr[i]);
        if(sum>0){
            sum-=2*q1.top();
            q1.pop();
            res++;
        }
    }
    sum=0;
    foe(i,m+1,n){
        sum+=arr[i];
        q2.push(-arr[i]);
        if(sum<0){
            sum+=2*q2.top();
            q2.pop();
            res++;
        }
    }
    cout<<res<<endl;
}
i32 main(){
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}