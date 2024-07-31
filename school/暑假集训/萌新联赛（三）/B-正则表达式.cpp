#include<bits/stdc++.h>
#define int long long 
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)

using i32=signed;
using namespace std;



bool check(array<i32,4> &arr){
    for(auto &i:arr){
        if(i<0||i>255) return false;
    }
    return true;
}
void solve(){
    int n;
    cin>>n;
    i32 num;
    i32 ans=0;
    string str;
    stringstream ss;
    array<i32,4> arr;
    foe(i,1,n){
        cin>>str;
        for(auto &it:str){
            if(it=='.') it=' ';
        }
        ss<<str;
        foe(j,0,3){
            ss>>arr[j];
        }
        if(check(arr)) ans++;
        ss.clear();
    }
    cout<<ans<<endl;
}

i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}