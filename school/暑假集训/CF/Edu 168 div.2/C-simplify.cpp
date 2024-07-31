#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)

using namespace std;
using i32=signed;
const int N=1e6+10;

typedef pair<int,char> PII;
PII q[N];
i32 hh,tt;

void solve(){
    int n;
    cin>>n;
    char ch;
    hh=0,tt=-1;
    int sum=0;
    foe(i,1,n){
        cin>>ch;
        if(hh<=tt&&(ch==')'||ch=='_')){
            auto t=q[hh++];
            sum+=i-t.first;
        }
        else q[++tt]={i,ch};
    }
    cout<<sum<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}