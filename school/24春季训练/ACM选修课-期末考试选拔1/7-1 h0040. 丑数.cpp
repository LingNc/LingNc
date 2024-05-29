#include <bits/stdc++.h>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
using namespace std;

vector<ll> l;
bool isSB(ll x);

void solve(){
    int n;
    l.push_back(2);
    while(1){
        cin>>n;
        if(n==0) break;
        if(n>l.size()){
            ll num=*l.rbegin()+1;
            while(n>l.size()){
                if(isSB(num)){
                    l.push_back(num);
                }
                num++;
            }
        }
        if(n-2<0)
            cout<<1<<endl;
        else
            cout<<l[n-2]<<endl;
    }
}

bool isSB(ll x){
    ll now=l.size()-1,n=0;
    while(now>=n){
        if(x%l[now]==0){
            x/=l[now];
        }
        now--;
    }
    if(x==2||x==3||x==5||x==1)
        return 1;
    else
        return 0;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
