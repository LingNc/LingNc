#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define all(a) a.begin(),a.end()
#define INF64 0x3f3f3f3f3f3f3f3f
#define INF32 0x3f3f3f3f
#define int long long
#define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;

const i32 N=0;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> b(n+2,vector<int>(m+2,0));
    priority_queue<int> q;
    foe(i,1,n-k+1){
        foe(j,1,m-k+1){
            b[i][j]++,b[i][j+k]--,b[i+k][j]--,b[i+k][j+k]++;
        }
    }
    foe(i,1,n){
        foe(j,1,m){
            b[i][j]=b[i][j]+b[i-1][j]+b[i][j-1]-b[i-1][j-1];
            q.push(b[i][j]);
        }
    }
    int num,t,res=0;
    cin>>num;
    vector<int> big(num,0);
    foe(i,1,num) cin>>big[i-1];
    sort(all(big),greater<int>());
    foe(i,1,num){
        res+=big[i-1]*q.top();
        q.pop();
        if(q.empty()) break;
    }
    cout<<res<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}