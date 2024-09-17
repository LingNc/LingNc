#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> a(m,0);
    for(int i=0;i<=m-1;i++) cin>>a[i];
    sort(a.begin(),a.end());
    int stu;
    for(int i=1;i<=q;i++){
        cin>>stu;
        if(stu<a[0]){
            cout<<a[0]-1<<endl;
            continue;
        }
        if(stu>a[m-1]){
            cout<<n-a[m-1]<<endl;
            continue;
        }
        int res=upper_bound(a.begin(),a.end(),stu)-a.begin();
        cout<<(a[res]-a[res-1])/2<<endl;
    }

}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    signed T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}