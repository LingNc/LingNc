#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
// #define endl '\n'
using namespace std;
using i32=int;
using i64=long long;
#define int long long
#define all(a) a.begin(),a.end()




void solve(){
    int n;
    cin>>n;
    unordered_map<string,string> mp;
    string t1,t2;
    foe(i,0,n){
        cin>>t1>>t2;
        mp[t1]=t2;
        mp[t2]=t1;
    }
    int cnt=0;
    int m;
    cin>>m;
    vector<string> temp(m);
    vector<string> ans;
    unordered_map<string,int> mp2;
    foe(i,0,m){
        cin>>temp[i];
        if(mp.count(temp[i])==0){
            ans.push_back(temp[i]);
        }
        else{
            if(mp2.count(temp[i])){
                mp2[temp[i]]=0;
            }
            else{
                mp2[mp[temp[i]]]=1;
            }
        }
    }
    // foe(i,0,m){
    //     if(find(all(temp),mp[temp[i]])==temp.end()){
    //         ans.push_back(temp[i]);
    //     }
    // }
    for(auto &it:mp2){
        if(it.second==1){
            ans.push_back(mp[it.first]);
        }
    }
    cout<<ans.size()<<endl;
    sort(all(ans));
    foe(i,0,ans.size()){
        if(i!=0) cout<<' ';
        cout<<ans[i];
    }
}

i32 main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}