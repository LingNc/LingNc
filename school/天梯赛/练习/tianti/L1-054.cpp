#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
// #define endl '\n'
using namespace std;
using i32=int;
using i64=long long;
#define int long long
typedef pair<int,int> PII;
#define all(a) a.begin(),a.end()

void print(vector<vector<char>> &mp){
    foe(i,1,mp.size()){
        foe(j,1,mp[i].size()){
            cout<<mp[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

void solve(){
    char ch;
    int n;
    cin>>ch>>n;
    cin.get();
    vector<vector<char>> mp(n+1,vector<char>(n+1,0));
    foe(i,1,n+1){
        foe(j,1,n+1){
            mp[i][j]=cin.get();
        }
        cin.get();
    }
    // print(mp);
    vector<vector<char>> mp2(n+1,vector<char>(n+1,0));
    int no=true;
    foe(i,1,n+1){
        foe(j,1,n+1){
            mp2[i][j]=mp[n-i+1][n-j+1];
        }
    }
    // print(mp2);
    foe(i,1,n+1){
        foe(j,1,n+1){
            if(mp[i][j]!=mp2[i][j]){
                no=false;
                break;
            }
            if(!no) break;
        }
    }
    if(no){
        cout<<"bu yong dao le"<<endl;
    }
    foe(i,1,n+1){
        foe(j,1,n+1){
            if(mp2[i][j]=='@'){
                cout<<ch;
            }
            else{
                cout<<mp2[i][j];
            }
        }
        cout<<endl;
    }
}

i32 main(){
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}