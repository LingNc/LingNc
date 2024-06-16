#include<bits/stdc++.h> 
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

void solve(){
    ios::sync_with_stdio(0),cin.tie(0);
    int N,K;
    cin>>N>>K;
    vector<int> space_b(N+2,0);
    int a,b;
    foe(i,1,K){
        cin>>a>>b;
        space_b[a]+=1;
        space_b[b+1]-=1;
    }
    //vector<int> space(N+2,0);
    int sum=0;
    foe(i,1,N){
        space_b[i]+=space_b[i-1];
        //cout<<space_b[i]<<" ";
    }
    sort(space_b.begin()+1,space_b.end()-1);
    cout<<space_b[N/2+1]<<endl;
}
int main( ){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}