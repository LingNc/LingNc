#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<vector>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define string char
#define endl '\n'
using namespace std;

void solve(){
    string name[100];
    cin>>name;
    int a;
    double b;
    cin>>a>>b;
    cout<<name<<' '<<(a+1)<<' '<<((int(b*1.2)<=600)?int(b*1.2):600)<<endl;
}

int main(){
    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}