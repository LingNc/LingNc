#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)

using namespace std;
ll C(ll n,ll m);
int main(){
    vector<ll> a,b;
    //vector<vector<int>> map(100000,vector<int>(100000,0));
    ll N,num=0;
    cin>>N;
    //map[1][1]=1;
    num++;
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    int flag=0;
    while(1){
        if(N==1){
            num++;
            break;
        }
        b.push_back(0);
        foe(i,0,a.size()-2){
            ll t=a[i]+a[i+1];
            b.push_back(t);
            num++;
            if(N==t){
                flag=1;
                break;
            }
        }
        if(flag==1) break;
        b.push_back(0);
        a.swap(b);
        b.clear();
    }
    cout<<num<<'\n';
    return 0;
}
ll C(ll n,ll m){
    ll ans=1;
    for(ll i=1;i<=m;i++){
        ans=ans*(n-m+i)/i; // 注意一定要先                乘再除
    }
    return ans;
}