#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int mp3[N];
void  solve(){
    int n,q;
    cin>>n>>q;
    memset(mp3,-1,sizeof mp3);
    for(int i=1;i<n;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        if(mp3[x]==-1) mp3[x]=z;
        else mp3[x]^=z;
        if(mp3[y]==-1) mp3[y]=z;
        else mp3[y]^=z;
    }
    while(q--) {
        int op;
        cin>>op;
        if(op==2) {
            int x;
            cin>>x;
            cout<<mp3[x]<<endl;
        }
        else {
            int x,y,z;
            cin>>x>>y>>z;
            mp3[x]^=z;
            mp3[y]^=z;
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}