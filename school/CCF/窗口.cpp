#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(b);i>=(b);i--)
#define INF64 0x3f3f3f3f3f3f3f3f
#define INF32 0x3f3f3f3f
#define all(a) a.begin(),a.end()
#define int long long
#define endl '\n'
using namespace std;
using i32=signed;
using i64=long long;

typedef vector<int> arr;
typedef pair<int,int> PII;

typedef struct win{
    int x1,x2,y1,y2;
    int name;
}Win;


void flash(vector<vector<int>> &fram,Win &w){
    foe(i,w.x1,w.x2){
        foe(j,w.y1,w.y2){
            fram[i][j]=w.name;
        }
    }
}

void solve(){
    vector<vector<int>> fram(2560,vector<int>(1440,0));
    int n,m;
    cin>>n>>m;
    vector<Win> q(n+1);
    Win t;
    foe(i,1,n){
        cin>>t.x1>>t.y1>>t.x2>>t.y2;
        t.name=i;
        q[i]=t;
        flash(fram,t);
    }
    int x,y;
    foe(i,1,m){
        cin>>x>>y;
        int temp=fram[x][y];
        if(temp) cout<<temp<<endl;
        else cout<<"IGNORED"<<endl;
        flash(fram,q[temp]);
    }
}

i32 main(){
    IOS;
    int T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}