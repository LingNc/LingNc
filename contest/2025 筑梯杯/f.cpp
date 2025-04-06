#include<bits/stdc++.h>
using namespace std;

struct an{
    long long u,v,w;
};

bool comp(an x,an y){
    if(x.w>y.w)return true;
    else return false;
}

int main(){
    an a[300005];
    long long i,j,k,n,m,t,v,s=0,x,y,u;
    cin>>t;
    while(t--){
        cin>>n;
        n--;
        for(i=0;i<n;i++){
            cin>>a[i].u>>a[i].v>>a[i].w;
        }
        sort(a,a+n,comp);
        x=a[0].u;y=a[0].v;
        for(i=n-1;i>0;i++){
            u=a[i].u;v=a[i].v;
            if(u==x){
                cout<<y<<" "<<v<<" "<<"0"<<"\n";
                break;
            }
            if(u==y){
                cout<<x<<" "<<v<<" "<<"0"<<"\n";
                break;
            }
            if(v==x){
                cout<<y<<" "<<u<<" "<<"0"<<"\n";
                break;
            }
            if(v==y){
                cout<<x<<" "<<u<<" "<<"0"<<"\n";
                break;
            }
        }
    }
}