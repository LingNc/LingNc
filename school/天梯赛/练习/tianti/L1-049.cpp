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

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    foe(i,0,n){
        cin>>a[i+1];
        a[i+1]*=10;
    }
    vector<int> b=a;
    vector<vector<int>> mp(n+1);
    int nums=0;
    while(true){
        int cnt=0;
        foe(i,1,n+1){
            if(a[i]!=0) cnt++;
        }
        if(!cnt) break;
        foe(i,1,n+1){
            if(a[i]!=0){
                nums++;
                a[i]--;
                if(cnt!=1||nums==1) mp[i].push_back(nums);
                else{
                    mp[i].push_back(++nums);
                }
            }
        }
    }
    foe(i,1,n+1){
        cout<<'#'<<i<<endl;
        foe(j,0,b[i]/10){
            foe(k,0,10){
                if(k!=0) cout<<' ';
                cout<<mp[i][j*10+k];
            }
            if(j!=b[i]/10-1) cout<<endl;
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