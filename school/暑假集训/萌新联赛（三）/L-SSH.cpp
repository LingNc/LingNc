#include<bits/stdc++.h>
#define int long long 
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define all(a) a.begin(),a.end()
using i32=signed;
using namespace std;
/*
3 2 2
ab cd
ef gki
lmn opq

1.1.1.1 2
alice 2 ab ef
bob 1 ef

8.8.8.8 2
googel 1 lmn
gg 3 ab ef lmn

googel 8.8.8.8 opq
bob 1.1.1.1 gki
*/



void solve(){
    i32 m,n,q;
    cin>>m>>n>>q;
    string pub,pri;
    unordered_map<string,string> pwd;
    foe(i,1,m){
        cin>>pub>>pri;
        pwd[pri]=pub;
    }
    
    map<string,vector<string>> data,user;
    string ip,us_name;
    i32 num,us_num;

    foe(i,1,n){
        cin>>ip>>num;
        foe(i,1,num){
            cin>>us_name>>us_num;
            data[ip].push_back(us_name);
            foe(i,1,us_num){
                cin>>pub;
                user[pub].push_back(us_name);
            }
        }
    }

    foe(i,1,q){
        cin>>us_name>>ip>>pri;
        pub=pwd[pri];
        if(count(all(user[pub]),us_name)&&count(all(data[ip]),us_name))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}

i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}