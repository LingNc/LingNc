#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
#define endl '\n'
using i32=int;
using i64=long long;
using namespace std;
#define int long long
typedef vector<int> arr;
using PII=pair<int,int>;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define all(a) a.begin(),a.end();

void solve(){
    int N,M,S;
    cin>>N>>M>>S;
    vector<deque<char>> qq(N+1);
    char temp;
    foe(i,1,N+1){
        foe(j,0,M){
            cin>>temp;
            qq[i].push_back(temp);
        }
    }
    int t;
    while(true){
        cin>>t;
        if(t==-1) break;
        if(t==0){
            if(qq[t].empty()) continue;
            cout<<qq[t].back();
            qq[t].pop_back();
        }
        else{
            if(qq[t].empty()) continue;
           if(qq[0].size()>=S){
                cout<<qq[0].back();
                qq[0].pop_back();
            }
            qq[0].push_back(qq[t].front());
            qq[t].pop_front();
        }
    }
}
i32 main(){
    IOS;
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}
