#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define long long
using i64=long long;
using namespace std;

const int N=1e5+10;

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    foe(i,0,n-1)
        cin>>arr[i];
    int l_num=arr[0],r_num=arr[n-1];
    int l=0,r=0;
    foe(i,0,n-1){
        if(arr[i]==l_num) l++;
        if(arr[i]!=l_num) break;
    }

    fod(i,n-1,0){
        if(arr[i]==r_num) r++;
        if(arr[i]!=r_num) break;
    }
    int sum;
    if(l_num==r_num)
        sum=min(l+r,n);
    else
        sum=max(l,r);
    cout<<n-sum<<endl;
}
signed main(){
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}