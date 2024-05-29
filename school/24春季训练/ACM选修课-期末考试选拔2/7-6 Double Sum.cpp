#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<queue>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(int i=a;i<=b;i++)
//priority_queue
using namespace std;
void priA(vector<int> &A){
    foe(i,0,A.size()-1){
        cout<<A[i]<<' ';
    }
    cout<<endl;
}
ll max(ll a,ll b){
    return (a>b)?a:b;
}
void solve(){
    ios::sync_with_stdio(0),cin.tie(0);
    int N;
    cin>>N;
    vector<ll> A(N+1,0);
    foe(i,1,N){
        cin>>A[i];
    }
    ll sum=0;
    foe(i,1,N)foe(j,i+1,N){
        sum+=max(A[j] - A[i],0);
    }
    cout<<sum<<endl;
}
int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
