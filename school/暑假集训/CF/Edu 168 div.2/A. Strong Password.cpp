#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)

using namespace std;
using i32=signed;
const int N=10;

void solve(){
    string pass;
    cin>>pass;
    char ch;
    bool flag=false;
    int len=pass.size()-2;
    foe(i,0,len){
        if(pass[i]==pass[i+1]){
            if(pass[i]=='z') ch=pass[i]-1;
            else if(pass[i]=='a') ch=pass[i]+1;
            else ch=pass[i]+1;
            pass.insert(pass.begin()+i+1,ch);
            flag=true;
            break;
        }
    }
    int i=0;
    if(pass[i]=='z') ch=pass[i]-1;
    else if(pass[i]=='a') ch=pass[i]+1;
    else ch=pass[i]+1;
    if(!flag){
        pass.insert(pass.begin(),ch);
    }
    cout<<pass<<endl;
}
i32 main(){
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}