#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
// #define endl '\n'
using namespace std;
using i32=int;
using i64=long long;
#define int long long
typedef pair<int,int> PII;
#define all(a) a.begin(),a.end()

const int N=1e5+10;

vector<int> a;
vector<PII> tree;
int dfs(int root,int left,int right){
    int k=0;
    foe(i,left,right+1){
        if(a[i]>=root){
            k=i;
            break;
        }
    }
    tree[root].first=dfs(a[k],left+1,k-1);
    tree[root].second=dfs(a[k],k+1,right);
    return a[k];
    };
void solve(){
    int n;
    cin>>n;
    tree.resize(n+1);
    a.resize(n+1);
    foe(i,0,n) cin>>a[i+1];
    int root=dfs(0,1,n);

}

i32 main(){
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}