#include<iostream>
#include<algorithm>
#define ll long long
#define endl '\n'
using namespace std;

int main(){
    int m,L,S,x,y;
    cin>>m>>L>>S>>x>>y;
    cout<<m*(L*x+S*y)<<endl;
    return 0;
}