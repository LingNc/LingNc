#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define all(a) a.begin(),a.end()
#define INF64 0x3f3f3f3f3f3f3f3f
#define INF32 0x3f3f3f3f
#define ll long long
#define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;

const i32 N=0;

//找到满足条件的第一个值,返回下标
int half(vector<int> &arr,int val,bool check(int,int)){
    i64 mid;
    i64 l=-1,r=arr.size();
    while(l+1<r){
        mid=l+r>>1;
        if(check(arr[mid],val)) r=mid;
        else l=mid;
    }
    return r;
}
bool check1(int num,int val){
    return num>=val;
}
bool check2(int num,int val){
    return num>val;
}
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> arr(n,0);
    foe(i,0,n-1) cin>>arr[i];
    int k;
    foe(i,1,q){
        cin>>k;
        int t1=half(arr,k,check1);
        int t2=half(arr,k,check2)-1;
        if(arr[t1]==k) cout<<t1<<' '<<t2<<endl;
        else cout<<-1<<' '<<-1<<endl;
    }
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}