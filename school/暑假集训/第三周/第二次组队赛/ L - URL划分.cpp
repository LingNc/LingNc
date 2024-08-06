#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define all(a) a.begin(),a.end()

using namespace std;
using i32=signed;
using i64=long long;

bool afind(string &str){
    int flag=0,res=0;
    for(auto &i:str){
        if(i=='=') res++;
    }
    if(res==1) return true;
    else return false;
}
void solve(){
    string web;
    cin>>web;
    vector<string> arr;
    int l=0,r=0,num=0;
    foe(i,0,web.size()-1){
        if(web[i]==':'){
            // cout<<web.substr(0,i)<<endl;
            arr.push_back(web.substr(0,i));
            l+=i+2;i+=3;
        }
        if(web[i]=='/'){
            arr.push_back(web.substr(l+1,i-l-1));
            l+=i-l;
        }
    }
    foe(i,0,arr.size()-1){
        if(i<2) cout<<arr[i]<<endl;
        else {
            if(afind(arr[i])) cout<<arr[i]<<endl;
        }
    }
}
i32 main(){
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}