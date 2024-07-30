#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define ll long long
using i64=long long;
using namespace std;
const int N=1e4+10;
typedef pair<int,int> PII;
bool cmp(PII a,PII b){
    return a.second<b.second;
}
void solve(){
    priority_queue<PII,vector<PII>,greater<PII>> q;
    int n;
    cin>>n;
    int num;
    foe(i,1,n){
        cin>>num;
        q.push({num,i});
    }
    PII t1,t2;
    vector<PII> res;
    t1=q.top(),q.pop();
    while(q.size()){
        t2=q.top(),q.pop();
        if(t1.first==t2.first){
            t2.first+=t1.first;
            q.push(t2);
            t1=q.top(),q.pop();
            if(!q.size()){
                res.push_back(t1);
                break;
            }
            continue;
        }
        else if(!q.size()){
            res.push_back(t1);
            res.push_back(t2);
        }
        else{
            res.push_back(t1);
            t1=t2;
        }
    }
    sort(res.begin(),res.end(),cmp);
    cout<<res.size()<<endl;
    for(auto &i:res) cout<<i.first<<' ';
    cout<<endl;
}
signed main(){
    int T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}