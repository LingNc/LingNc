#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
using namespace std;

string num;

void solve(){
    string res;
    cin>>num;
    int pa=-1,pb=-1;
    while(num[++pa]%2==1&&pa<num.size());
    while(num[++pb]%2==0&&pb<num.size());
    while(pa<num.size()||pb<num.size()){
        if(pa>=num.size()||pb<num.size()&&num[pb]<num[pa]){
            res+=num[pb];
            while(num[++pb]%2==0&&pb<num.size());
        }
        else if(pb>=num.size()||pa<num.size()&&num[pa]<num[pb]){
            res+=num[pa];
            while(num[++pa]%2==1&&pa<num.size());
        }
    }
    cout<<res<<endl;
}

signed main(){
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}