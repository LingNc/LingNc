#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;


int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,sum=0;
    cin>>n;
    ll a[n];
    memset(a,0,sizeof(ll));
    for(int i=0;i<=n-1;i++){
        cin>>a[i];
        sum+=a[i];
    }
    int m;
    cin>>m;
    ll x[m],y[m];
    memset(x,0,sizeof(ll));
    memset(y,0,sizeof(ll));
    for(int i=0;i<=m-1;i++){
        cin>>x[i]>>y[i];
    }

    sort(a,a+n);
    int k=0;
    ll gold=0;
    bool flag;
    for(int j=0;j<=m-1;j++){
        flag=0;gold=0;
        for(int i=0;i<=n-1;i++){
            if(a[i]>=x[j]){
                k=a[i];
                flag=1;
                break;
            }
        }

        if(flag==0){
            gold+=x[j]-a[n-1];
            k=a[n-1];
        }

        gold+=y[j]-(sum-k);
        cout<<gold<<'\n';
    }
    return 0;
}

