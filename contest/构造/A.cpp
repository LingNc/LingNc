#include<iostream>
#include<cmath>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int N;
    cin>>N;
    ll n,k;
    while(N--){
        cin>>n>>k;
        ll res;
        while(k<n){
            k*=2;
        }
        if(k%n==0)
            res=k/n;
        else
            res=k/n+1;
        cout<<res<<'\n';
    }
    return 0;
}