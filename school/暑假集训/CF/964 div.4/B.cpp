#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define all(a) a.begin(),a.end()

using namespace std;
using i32=signed;
using i64=long long;

void solve(){
    vector<int> arr(4,0);
    foe(i,0,3) cin>>arr[i];
    int res=0;
    if(arr[0]>=arr[2]&&arr[1]>=arr[3]&&!(arr[0]==arr[2]&&arr[1]==arr[3])) res++;
    if(arr[1]>=arr[3]&&arr[0]>=arr[2]&&!(arr[1]==arr[3]&&arr[0]==arr[2])) res++;
    if(arr[0]>=arr[3]&&arr[1]>=arr[2]&&!(arr[0]==arr[3]&&arr[1]==arr[2])) res++;
    if(arr[1]>=arr[2]&&arr[0]>=arr[3]&&!(arr[1]==arr[2]&&arr[0]==arr[3])) res++;
    cout<<res<<endl;
}
i32 main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}