#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;
void solve();
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    //int T;cin>>T;while(T--)
        solve();
    
}
void solve(){
    int p,num;
    cin>>p>>num;
    cout<<num%2<<' '<<p*(int)pow(2,num/2)<<endl;
}