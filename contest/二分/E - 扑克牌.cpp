#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long
#define endl '\n'

using namespace std;
ll my_find();
bool check(ll x);
ll n,c[51],joker;
ll L,sum=0;
int main(){
    cin>>n>>joker;
    for(int i=0;i<=n-1;i++){
        cin>>c[i];
        sum+=c[i];
    }
    c[n]=joker;
    sum+=joker;
    sort(c,c+n);
    L=(n+1)*c[n-1];
    cout<<my_find()<<endl;
    return 0;
}
ll my_find(){
    ll l=-1,r=L+1,mid;
    while(l+1!=r){
        mid=(l+r)>>1;
        if(check(mid))
            l=mid;
        else
            r=mid;
    }
    return l;
}
bool check(ll x){
    if(x*n>sum) return 0;
    else return 1;
}