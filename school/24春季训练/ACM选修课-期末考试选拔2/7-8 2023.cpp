#include<iostream>
#include<algorithm>
#include<string>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(int i=a;i<=b;i++)

using namespace std;

void solve(){
    string str;
    cin>>str;
    *str.rbegin()='4';
    cout<<str;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
