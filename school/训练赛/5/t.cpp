#include <bits/stdc++.h>
#include<map>
#define ll long long
using namespace std;

const int N=2000005;

ll n,a,b,c,d,e,f,m,x[N],y[N],z[N];


int main(){
    ll t;
    cin>>n;
    x[0]=0;
    b=2000005;
    c=0;
    f=0;
    memset(z,0,sizeof(z));
    for(int i=1;i<=n-1;i++){
        cin>>a;
        x[i]=a+x[i-1];
        b=min(b,x[i]);

    }



    if(b!=1)
        c=1-b;
    else c=1;
    y[1]=c;
    z[y[1]]=1;
    for(int i=1;i<=n-1;i++){
        y[i+1]=x[i]+c;
        e=y[i+1];
        z[e]=1;
    }
    for(int i=1;i<=n;i++){
        if(z[i]==0){
            f=1;
            break;
        }
    }
    if(f==1)cout<<"-1";
    else{
        for(int i=1;i<=n;i++){
            cout<<y[i]<<" ";
        }
    }




    return 0;
}