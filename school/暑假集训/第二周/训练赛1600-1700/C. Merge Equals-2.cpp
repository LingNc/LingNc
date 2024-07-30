#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define int long long
using i64=long long;
using namespace std;
const int N=1e4+10;
typedef pair<int,int> PII;

void solve(){
    unordered_map<int,int> m;
    int n;
    cin>>n;
    vector<int> arr(n,0);
    foe(i,0,n-1){
        cin>>arr[i];
        //m存前一个下标idx
        int idx=m[arr[i]];
        while(idx&&arr[idx-1]&&idx-1!=i){
            arr[idx-1]=0;
            arr[i]*=2;
            idx=m[arr[i]];
        }
        m[arr[i]]=i+1;
    }
    int sum=0;
    for(auto &i:arr)
        if(i!=0) sum++;
    cout<<sum<<endl;
    for(auto &i:arr)
        if(i!=0) cout<<i<<' ';
    cout<<endl;
}
signed main(){
    int T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}