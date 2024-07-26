#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define ll long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'

using namespace std;

const int N=1e6+10;
int b,p,f,h,c;
void solve(){
    cin>>b>>p>>f;
    cin>>h>>c;
    int tol=min(b/2,p+f);
    int sel_h=0,sel_c=0;
    if(h>c){
        sel_h=min(p,tol);
        sel_c=tol-sel_h;
    }
    else{
        sel_c=min(f,tol);
        sel_h=tol-sel_c;
    }
    cout<<sel_h*h+sel_c*c<<endl;
}
int main(){
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}