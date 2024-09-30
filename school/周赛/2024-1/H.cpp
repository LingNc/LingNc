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
    int n;
    cin>>n;
    arr a(n+1,0),b(n+1,0);
    foe(i,1,n) cin>>a[i];
    int flag=0;
    foe(i,2,n){
        b[i-1]=a[i]-a[i-1];
    }
    int res1=0,res2=0,res3=0,res4=0;
    foe(i,1,n-1){
        if(b[i]>=0) res1++;
        if(b[i]<=0) res2++;
        if(i>1){
            if(b[i-1]<0&&b[i]>0) res3++;
            if(b[i-1]>0&&b[i]<0) res4++;
        }
    }
    if(res1==n-1||res2==n-1) cout<<"Binary Search"<<endl;
    else if(res3+res4==1) cout<<"Ternary Search"<<endl;
    else cout<<"QwQ"<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}