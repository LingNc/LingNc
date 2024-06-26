#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<climits>
#include<cstdlib>
#include<stack>
#include<queue>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

int main(){
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,P;
    cin>>n>>P;
    vector<ll> p(n,0);
    foe(i,0,n-1){
        cin>>p[i];
    }
    //大模拟
    /*
    foe(j,1,n-1)
        foe(k,j+1,n){
            if(p[j]+p[k]>p[0]&&p[0]+p[j]>p[k]&&p[0]+p[k]>p[j]){
                num++;
            }
        }
    */
    ll num=0;
    sort(p.begin(),p.end());
    //vector<ll>::iterator l,r;
    foe(i,0,n-1){
        auto l=upper_bound(p.begin()+i+1,p.end(),abs(p[i]-P));
        auto r=lower_bound(p.begin()+i+1,p.end(),p[i]+P);
        num+=r-l;
    }
    cout<<num<<endl;
    return 0;
}