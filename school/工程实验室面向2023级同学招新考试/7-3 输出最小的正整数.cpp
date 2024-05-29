#include<iostream>
#include<algorithm>
#include<climits>
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
#define endl '\n'
using namespace std;

void solve(){
    int n;
    cin>>n;
    int min=INT_MAX;
    int num,flag=0;
    foe(i,0,n){
        cin>>num;
        if(num>0) flag=1;
        if(num>0&&num<min) min=num;
    }
    if(flag==0) cout<<"not found"<<endl;
    else cout<<min<<endl;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}