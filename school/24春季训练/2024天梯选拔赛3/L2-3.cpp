#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<set>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;
void solve();
int main(){
    ios::sync_with_stdio(0);
    //int T;cin>>T;while(T--)
        solve();
    
}
struct peo{
    int x,y;
};
void solve(){
    vector<int> s;
    int n,m;
    cin>>n;
    vector<peo> L(n);
    foe(i,0,n-1){
        cin>>L[i].x>>L[i].y;
    }
    cin>>m;
    int num=0;
    foe(i,1,m){
        cin>>num;
        s.push_back(num);
    }
    foe(i,0,n-1){
        if()
    }
}