#include<bits/stdc++.h>
#define int long long 
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)

using i32=signed;
using namespace std;
using u64=unsigned long long;
const double Pi=3.1415926535897;
typedef pair<double,double> PII;

vector<u64> PI={3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6};
vector<u64> mul(vector<u64> &A, u64 b)
{
    vector<u64> C;

    u64 t = 0;
    for (u64 i = 0; i < A.size() || t; i ++ )
    {
        if (i < A.size()) t += (u64)A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}

void solve(){
    //cin>>n;
    //vector<PII> res;
    u64 PP,A4;
    cin>>PP>>A4;
    vector<u64> res;
    res=mul(PI,A4);
    for(auto i:res) cout<<i;
    // vector<PII> arr;
    // double P,A;
    // foe(i,1,n){
    //     cin>>P>>A;
    //     arr.push_back({P,A});
    //     res.push_back({fabs(P/A-Pi),i-1});
    // }
    // sort(res.begin(),res.end());
    // int ans=res[0].second;
    // cout<<arr[ans].first<<' '<<arr[ans].second<<endl;
}

i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}