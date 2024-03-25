#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

int main(){
    string s;
    cin>>s;
    auto i=s.rbegin();
    for(i;i!=s.rend();i++){
        cout<<*i;
    }
    cout<<endl;
    return 0;
}