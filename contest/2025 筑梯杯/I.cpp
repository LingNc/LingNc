#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
//#define endl '\n'
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define PII pair<int,int>
using i32=int;
using i64=long long;
#define int long long
const i64 mod=(i64)1e9+7;

void exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1,y=0;
        return;
    }
    exgcd(b,a%b,y,x);
    y-=a/b*x;
}

i64 pow(i64 x,int y){
    i64 ans=1;
    for(;y;y>>=1){
        if(y&1) ans=ans*x%mod;
        x=x*x%mod;
    }
    return ans;
}

int inv_ex(int a){
    int x,y;
    exgcd(a,mod,x,y);
    return x;
}

int inv(int a){
    return pow(a,mod-2);
}

void solve(){
    int n;
    cin>>n;
    int temp=0,res=1;
    foe(i,0,n){
        int x,y;
        cin>>x>>y;
        temp=pow(x,y);
        res=(res*temp)%mod;
    }
    res+=mod*mod;
    int b;
    cin>>b;
    // int inv_b=inv(b);
    int ans=res/b;
    cout<<ans%mod<<endl;
}

i32 main(){
	IOS;
	i32 T=1;
//	cin>>T;
	while(T--) solve();
}
