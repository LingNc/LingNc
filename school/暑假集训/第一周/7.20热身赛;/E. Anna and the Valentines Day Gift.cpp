#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define ll long long
using i64=long long;
using namespace std;

const int N=1e5+10;

i64 have_0(string str){
    i64 t=str.size()-1;
    i64 sum=0;
    fod(i,t,0){
        if(str[i]=='0')
            sum++;
        else
            break;
    }
    return sum;
}
void solve(){
    int n,m;
    cin>>n>>m;
    string temp;
    vector<i64> res;
    i64 tol=0;
    foe(i,1,n){
        cin>>temp;
        tol+=temp.size();
        res.push_back(have_0(temp));
    }
    sort(res.begin(),res.end(),greater<int>());
    int sum=0;
    foe(i,0,n-1){
        if(i%2==1) continue;
        if(res[i]==0) break;
        sum+=res[i];
    }
    if(tol-sum>=m+1) cout<<"Sasha"<<endl;
    else cout<<"Anna"<<endl;
}
signed main(){
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}