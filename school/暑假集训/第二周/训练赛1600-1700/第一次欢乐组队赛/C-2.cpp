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
const int N=3e5+10;
int heap[N];
vector<int> res;
void DtoN(int d,int n){
    res.clear();
    while(d){
        res.push_back(d%n);
        d/=n;
    }
    reverse(all(res));
}
int sum_res(vector<int> &num){
    int ans=0;
    for(auto &i:num)
        ans+=i;
    return ans;
}
void solve(){
    int n,p,f=1;
    cin>>n>>p;
    foe(i,1,n){
        cin>>heap[i];
        if(heap[i]%2) f=-f;
        
    }

    if(p%2){
        if(f==-1) cout<<"GOOD"<<endl;
        else cout<<"BAD"<<endl;
        return ;
    }

    int sum=0;
    foe(i,1,n){
        DtoN(heap[i],p);
        sum+=sum_res(res);
    }
    if(sum%2) cout<<"GOOD"<<endl;
    else cout<<"BAD"<<endl;
}
i32 main(){
    int T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}