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
    int N;
    cin>>N;
    string ans;
    foe(i,1,4*N){
        cin>>ans;
        if(*ans.rbegin()=='T') cout<<ans[0]-'A'+1;
        ans.clear();
    }
}