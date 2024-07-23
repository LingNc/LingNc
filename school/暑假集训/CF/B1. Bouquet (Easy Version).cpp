#include<iostream>
#include<algorithm>
#include<queue>
#define int long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

int solve(int n,int m){
    priority_queue<int> q;
    int num;
    foe(i,1,m){
        cin>>num;
        q.push(num);
    }

}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T=1;
    cin>>T;
    int n,m;
    while(T--){
        cin>>n>>m;
        cout<<solve(n,m)<<endl;
    }
    return 0;
}